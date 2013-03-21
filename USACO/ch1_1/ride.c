/*
ID: saki451
LANG: C
TASK: ride
*/

#include<stdio.h>

int main(){

	FILE *fin, *fout;
	fin = fopen("ride.in", "r");
	fout = fopen("ride.out", "w");

	char str1[7], str2[7];
	int i, c1=1, c2=1;

	fscanf(fin, "%s%s", &str1, &str2);

	for(i=0; str1[i]!='\0'; i++)
		c1 = c1*(str1[i]-'A'+1) % 47;
	for(i=0; str2[i]!='\0'; i++)
		c2 = c2*(str2[i]-'A'+1) % 47;
	
	if(c1%47 == c2%47)
		fprintf(fout, "GO\n");
	else
		fprintf(fout, "STAY\n");

	return 0;
}

