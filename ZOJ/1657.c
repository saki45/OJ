#include<stdio.h>
#include<string.h>

int main(){
	int isPrime[32769], i, j, N, count, pCount, primes[10000];
	memset(isPrime, 0, sizeof(isPrime));
	pCount = 0;
	for(i=2; i<32769; i++){
		if(isPrime[i] == 0){
			j = 2*i;
			primes[pCount++] = i;
			while(j < 32769){
				isPrime[j] = 1;
				j += i;
			}
		}
	}

	while(scanf("%d", &N) && N){
		count = 0;
		i = 0;
		j = pCount-1;
		while(i <= j){
			if(primes[i]+primes[j]<N)
				i++;
			else if(primes[i] + primes[j] > N)
				j--;
			else{
				i++;
				j--;
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
