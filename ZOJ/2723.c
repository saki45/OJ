#include<stdio.h>

int getPrimeMap(int primeMap[], int primes[]){
	primeMap[0] = 0;
	primeMap[1] = 0;
	int i, j, k;
	for(i=2; i<500001; i++)
		primeMap[i] = 1;
	i = 2;
	k = 0;
	while(i < 500001){
		if(primeMap[i] == 1){
			primes[k++] = i;
			j = 2*i;
			while(j < 500001){
				primeMap[j] = 0;
				j += i;
			}
		}
		i++;
	}
	return k;
}

int main(){
	int primeMap[500001], primes[45000], N, i, prime, isSemi, nPrime;
	nPrime = getPrimeMap(primeMap, primes);
	while(scanf("%d", &N) != EOF){
		if(N < 500001 && primeMap[N]){
			printf("No\n");
			continue;
		}

		i = 0;
		prime = primes[i];
		isSemi = 0;
		while(i < nPrime && prime*prime <= N){
			if(N%prime == 0 && primeMap[N/prime]){
				isSemi = 1;
				printf("Yes\n");
				break;
			}
			i++;
			prime = primes[i];
		}
		if(!isSemi)
			printf("No\n");
	}

	return 0;
}
