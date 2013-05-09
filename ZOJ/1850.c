// This code is WA
#include<stdio.h>

typedef long long LL;

int main(){
	LL a, b, i, countA, j, countB, canDivide, tb;
	while(scanf("%Ld%Ld", &a, &b) != EOF){
		if(b == 0){
			printf("%Ld does not devide %Ld!\n", b, a);
			continue;
		}
		if(b == 1 || b <= a){
			printf("%Ld devides %Ld!\n", b, a);
			continue;
		}
		if(a < 2){
			printf("%Ld does not devide %Ld!\n", b, a);
			continue;
		}

		canDivide = 1;
		tb = b;
		i = 2;
		while(tb > 1){
			countA = 0;
			countB = 0;
			while(tb % i == 0){
				tb /= i;
				countB++;
			}
			j = i;
			while(j < a && countA < countB){
				countA += a/j;
				j *= i;
			}

			if(countA < countB){
				canDivide = 0;
				break;
			}
			i++;
		}

		if(canDivide)
			printf("%Ld divides %Ld!\n", b, a);
		else
			printf("%Ld does not divide %Ld!\n", b, a);

	}
	return 0;
}
