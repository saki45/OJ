#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char buf[10000], *str, *tok;
	int st, N, prevN, isFirst = 1, diff, prevDiff;
	while(1){
		fgets(buf, sizeof(buf), stdin);
		str = buf;
		tok = strtok(str, " \n");
		st = atoi(tok);
		if(st == 5280)
			break;
		if(!isFirst)
			printf("\n");

		prevN = 0;
		prevDiff = st*st;

		while((tok=strtok(NULL, " \n")) != NULL){
			N = atoi(tok);
			diff = (N-st)*(N-st);
			if(N == st)
				printf("Moving from %d to %d: found it!\n", prevN, N);
			else if(diff == prevDiff)
				printf("Moving from %d to %d: same.\n", prevN, N);
			else if(diff > prevDiff)
				printf("Moving from %d to %d: colder.\n", prevN, N);
			else
				printf("Moving from %d to %d: warmer.\n", prevN, N);
				
			prevN = N;
			prevDiff = diff;
		}
		isFirst = 0;
	}
	return 0;
}
