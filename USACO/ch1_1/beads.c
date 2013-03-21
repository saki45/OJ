/*
ID: saki451
PROG: beads
LANG: C
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fin, *fout;
	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");

	int N;
	fscanf(fin, "%d\n", &N);

	char *str = (char*)malloc(2*N*sizeof(char));
	int i;
	for(i=0; i<N; i++){
		fscanf(fin, "%c", &str[i]);
		str[i+N] = str[i];
	}

	char curColor = 0;
	int w=0, lPrev= 0, lCur=0, maxLength = 0;
	for(i=0; i<N<<1; i++){
		if(str[i] == 'w'){
			lCur ++;
			w ++;
		}
		else if(str[i] == curColor){
			lCur ++;
			w = 0;
		}
		else{
			if(lPrev+lCur > maxLength)
				maxLength = lPrev + lCur;
			lPrev = lCur - w;
			lCur = w + 1;
			w = 0;
			curColor = str[i];
		}
		//printf("%c %d %d %d\n", str[i], lPrev, lCur, w);
	}
	if(lPrev+lCur > maxLength)
		maxLength = lPrev + lCur;
	maxLength = maxLength>N? N:maxLength;
	fprintf(fout, "%d\n", maxLength);
	printf("%d\n", maxLength);
	free(str);

	return 0;
}
