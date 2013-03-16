/*
ID: saki451
PROG: friday
LANG: C
*/

#include<stdio.h>
#include<stdlib.h>

int isLeapYear(int N){
	if(N % 100 == 0)
		return N%400==0 ? 1 : 0;
	return N%4==0 ? 1 : 0;
}

int main(){
	FILE *fin, *fout;
	fin = fopen("friday.in","r");
	fout = fopen("friday.out","w");

	int N;
	fscanf(fin, "%d", &N);

	int thisYear = 1900;
	int *count = (int*)malloc(7*sizeof(int));
	int totalDay = 13;

	while(thisYear < 1900+N){
		// Jan
		count[totalDay % 7]++;
		totalDay += 31;

		// Feb
		count[totalDay % 7]++;
		if(isLeapYear(thisYear)){
			totalDay += 29;
		}
		else{
			totalDay += 28;
		}

		// Mar
		count[totalDay % 7]++;
		totalDay += 31;

		// Apr
		count[totalDay % 7]++;
		totalDay += 30;

		// May
		count[totalDay % 7]++;
		totalDay += 31;

		// Jun
		count[totalDay % 7]++;
		totalDay += 30;

		// Jul
		count[totalDay % 7]++;
		totalDay += 31;

		// Aug
		count[totalDay % 7]++;
		totalDay += 31 ;

		// Sep
		count[totalDay % 7]++;
		totalDay += 30;

		// Oct
		count[totalDay % 7]++;
		totalDay += 31;

		// Nov
		count[totalDay % 7]++;
		totalDay += 30;

		// Dec
		count[totalDay % 7]++;
		totalDay += 31;

		thisYear ++;
	}

	int i;
	for(i=6; i<12; i++){
		fprintf(fout, "%d ", count[i%7]);
		printf("%d ", count[i%7]);
	}
	fprintf(fout, "%d\n", count[5]);
	printf("%d\n", count[5]);
	free(count);
}
