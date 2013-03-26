#include<stdio.h>

int main(){
	int N, amount, nQ, nD, nN, i;
	scanf("%d", &N);
	i = 1;
	while(i <= N){
		scanf("%d",&amount);
		nQ = amount / 25;
		amount -= 25*nQ;
		nD = amount / 10;
		amount -= 10*nD;
		nN = amount / 5;
		amount -= 5*nN;
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", i++, nQ, nD, nN, amount);
	}
	return 0;
}
