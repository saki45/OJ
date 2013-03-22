#include<stdio.h>
#include<stdlib.h>

#define SUMMAP_SIZE 100
#define DIFFMAP_SIZE 100

void getPrimeMap(int *primeMap, int N){
	primeMap[0] = 0;
	primeMap[1] = 0;
	int i;

	for(i=2; i<N; i++)
		primeMap[i] = 1;

	for(i=2; i<N; i++){
		if(primeMap[i]){
			int j=i*2;
			while(j<N){
				primeMap[j] = 0;
				j += i;
			}
		}
	}
}

void getSumMap(int *sumMap1, int *sumMap2){
	int i, ti, digit;
	for(i=0; i<SUMMAP_SIZE; i++){
		sumMap1[i] = 0;
		sumMap2[i] = 0;
		ti = i;
		while(ti > 0){
			digit = ti % 10;
			sumMap1[i] += digit;
			sumMap2[i] += digit*digit;
			ti /= 10;
		}
	}	
}

void getDigitSum(long long num, int *sum1, int *sum2, int *sumMap1, int *sumMap2){
	*sum1 = 0;
	*sum2 = 0;

	int last = 0;

	while(num > 0){
		last = num % SUMMAP_SIZE;
		*sum1 += sumMap1[last];
		*sum2 += sumMap2[last];
		num /= SUMMAP_SIZE;
	}
}

void getDiffMap(int *diffMap1, int *diffMap2, int *sumMap1, int *sumMap2){

	int *tmpSum1 = (int*)calloc(DIFFMAP_SIZE, sizeof(int));
	int *tmpSum2 = (int*)calloc(DIFFMAP_SIZE, sizeof(int));

	int i, sum1, sum2;
	diffMap1[0] = 0;
	diffMap2[0] = 0;

	for(i=1; i<DIFFMAP_SIZE; i++){ 
		getDigitSum(i, &sum1, &sum2, sumMap1, sumMap2);
		tmpSum1[i] = sum1;
		tmpSum2[i] = sum2;
	}

	for(i=1; i<DIFFMAP_SIZE; i++){
		diffMap1[i] = tmpSum1[i] - tmpSum1[i-1];
		diffMap2[i] = tmpSum2[i] - tmpSum2[i-1];
	}

	free(tmpSum1);
	free(tmpSum2);
}

int main(){
	int T;
	scanf("%d", &T);
	int *primeMap = (int*)malloc(1500*sizeof(int));
	getPrimeMap(primeMap, 1500);
	
	int *sumMap1 = (int*)malloc(SUMMAP_SIZE*sizeof(int));
	int *sumMap2 = (int*)malloc(SUMMAP_SIZE*sizeof(int));
	int *diffMap1 = (int*)malloc(DIFFMAP_SIZE*sizeof(int));
	int *diffMap2 = (int*)malloc(DIFFMAP_SIZE*sizeof(int));
	getSumMap(sumMap1, sumMap2);
	getDiffMap(diffMap1, diffMap2, sumMap1, sumMap2);

	long long A, B, curNum, count;
	int sum1, sum2, curLoop;
	while(T>0){

		scanf("%Ld %Ld", &A, &B);
		count = 0;

		curNum = A;
		while(curNum <= B){
			curLoop = curNum % DIFFMAP_SIZE;
			getDigitSum(curNum, &sum1, &sum2, sumMap1, sumMap2);
			if(primeMap[sum1] && primeMap[sum2]){
				//printf("%Ld ", curNum);
				count ++;
			}

			curLoop++;
			curNum++;
			while(curNum<=B && curLoop<DIFFMAP_SIZE){
				sum1 += diffMap1[curLoop];
				sum2 += diffMap2[curLoop];
				if(primeMap[sum1] && primeMap[sum2]){
					//printf("%Ld ", curNum);
					count ++;
				}
				curNum++;
				curLoop++;
			}
		}
		printf("%Ld\n", count);
		T--;
	}

	free(primeMap);
	free(sumMap1);
	free(sumMap2);
	free(diffMap1);
	free(diffMap2);
}
