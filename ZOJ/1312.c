#include<stdio.h>
#include<stdlib.h>

int getPrimeMap(int primeMap[]){
	int i, count, j;
	for(i=0;i<=1000;i++)
		primeMap[i] = 1;
	count = 1;
	i = 2;
	while(i <= 1000){
		if(primeMap[i] == 1){
			count ++;
			j = 2*i;
			while(j <= 1000){
				primeMap[j] = 0;
				j += i;
			}
		}
		i++;
	}
	return count;
}

void getPrimeList(int primeMap[], int *primeList){
	int i=1, j=0;
	while(i<=1000){
		if(primeMap[i])
			primeList[j++] = i;
		i++;
	}
}

int bSearch(int *primeList, int count, int key){
	if(key == 1)
		return 0;
	if(key > primeList[count-1])
		return count-1;
	int st=0, ed=count-1, mid;
	while(st <= ed){
		mid = (st+ed)>>1;
		if(primeList[mid] == key)
			return mid;
		else if(primeList[mid] > key)
			ed = mid-1;
		else
			st = mid+1;
	}
	return ed;
}

int main(){
	int primeMap[1001], count, *primeList, N, C, idx, st, ed, mid;
	count = getPrimeMap(primeMap);
	primeList = (int*)calloc(count, sizeof(int));
	getPrimeList(primeMap, primeList);
	while(scanf("%d %d", &N, &C) != EOF){
		idx = bSearch(primeList, count, N);
		if((idx+1)%2 == 1){
			mid = idx>>1;
			st = mid-C+1>=0?mid-C+1:0;
			ed = mid+C-1<=idx?mid+C-1:idx;
		}
		else{
			mid = idx>>1;
			st = mid-C+1>=0?mid-C+1:0;
			ed = mid+C<=idx?mid+C:idx;
		}
		printf("%d %d:", N, C);
		for(idx=st; idx<=ed; idx++)
			printf(" %d", primeList[idx]);
		printf("\n\n");
	}

	free(primeList);
	return 0;
}
