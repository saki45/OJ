#include<stdio.h>
#include<string.h>

#define MAXSIZE 1000000

int bSearch(int primes[], int count, int value){
	int st = 1, ed = count, mid;
	while(st <= ed){
		mid = (st+ed)>>1;
		if(primes[mid] == value)
			return mid;
		else if(primes[mid] > value)
			ed = mid-1;
		else
			st = mid+1;
	}
	return st;
}

int main(){
	int primeTable[MAXSIZE], primes[500000], pCount, i, j, n;
	memset(primeTable, 0, sizeof(primeTable));

	i = 2;
	pCount = 0;
	while(i < MAXSIZE){
		if(primeTable[i] == 0){
			primeTable[i] = 1;
			primes[pCount++] = i;
			j = i*2;
			while(j < MAXSIZE){
				primeTable[j] = 1;
				j += i;
			}
		}
		i++;
	}

	while(scanf("%d", &n) && n){
		i = 1;
		j = bSearch(primes, pCount-1, n-3);

		while(primes[i] + primes[j] != n){
			if(primes[i]+primes[j] < n)
				i++;
			if(primes[i]+primes[j] > n)
				j--;
		}
		printf("%d = %d + %d\n", n, primes[i], primes[j]);
	}
	return 0;
}
