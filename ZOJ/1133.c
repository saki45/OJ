#include<stdio.h>
#include<math.h>

#define MAXPRIME 11000

int getPrimes(int primeMap[], int primeList[], int primeSumList[]){
	int i, j, n, tmp, tmpSum;
	for(i=0; i<MAXPRIME; i++){
		primeMap[i] = 1;
		primeList[i] = 1;
		primeSumList[i] = 0;
	}

	i = 2;
	n = 0;
	while(i < MAXPRIME){
		if(primeMap[i] == 1){
			primeList[n] = i;
			tmp = i;
			tmpSum = 0;
			while(tmp){
				tmpSum += tmp%10;
				tmp /= 10;
			}
			primeSumList[n++] = tmpSum;

			j = 2*i;
			while(j < MAXPRIME){
				primeMap[j] = 0;
				j += i;
			}
		}
		i++;
	}
	return n;
}

int isSmith(int N, int primeList[], int primeSumList[], int nPrime){
	int sumN, sumF, tFactor, tmp, p, sqrtN;
	sqrtN = (int)sqrt(N);
	p = 0;
	tFactor = primeList[0];
	tmp = N;
	sumN = 0;

	while(tmp){
		sumN += tmp%10;
		tmp /= 10;
	}

	tmp = N;
	sumF = 0;
	while(tFactor < sqrtN + 1 && tmp > 0){
		while(tmp % tFactor == 0 && tmp > 1){
			sumF += primeSumList[p];
			tmp /= tFactor;
		}
		tFactor = primeList[++p];
	}
	if(tmp == N)
		return 0;
	else if(tmp > 1){
		while(tmp){
			sumF += tmp%10;
			tmp /= 10;
		}
	}
	//printf("%d %d %d\n", N, sumN, sumF);
	return sumN == sumF;
}

int main(){
	int primeMap[MAXPRIME], primeList[MAXPRIME], primeSumList[MAXPRIME], nPrime, N;
	nPrime = getPrimes(primeMap, primeList, primeSumList);

	while(scanf("%d", &N) != EOF && N){
		N++;
		while(!isSmith(N, primeList, primeSumList, nPrime))	
			N++;
		printf("%d\n", N);
	}

	return 0;
}
