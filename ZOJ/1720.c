#include<stdio.h>

void printCoef(int coef[]){
	int i=0, p;
	while(coef[i]==0 && i<8)
		i++;

	if(i==8){
		printf("%d\n", coef[8]);
		return;
	}

	p = 8-i;
	if(coef[i]== 1)
		printf("x");
	else if(coef[i] == -1)
		printf("-x");
	else
		printf("%dx", coef[i]);
	if(i<7)
		printf("^%d", p);
	i++;

	while(i<9){
		if(coef[i] == 0){
			i++;
			continue;
		}

		if(coef[i] > 0)
			printf(" + ");
		else{
			printf(" - ");
			coef[i] = - coef[i];
		}
		if(i == 8)
			printf("%d", coef[i]);
		else{
			if(coef[i] != 1)
				printf("%d", coef[i]);
			if(i != 7){
				p = 8-i;
				printf("x^%d", p);
			}
			else
				printf("x");
		}
		i++;
	}
	printf("\n");
}

int main(){
	int coef[9], i;
	while(scanf("%d", &coef[0]) != EOF){
		for(i=1; i<9; i++)
			scanf("%d", &coef[i]);
		printCoef(coef);
	}
	return 0;
}
