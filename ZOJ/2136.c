#include<stdio.h>

#define MAX 10005

int bSearch(int aux[], int tmp, int curLongest){
	if(tmp < aux[1])
		return 1;
	int st=1, ed = curLongest, mid;
	while(st <= ed){
		mid = (st+ed)>>1;
		if(aux[mid] >= tmp)
			ed = mid-1;
		else
			st = mid+1;
	}
	return st;
}

int main(){
	int nBlock, N, aux[1005], curLongest, i, tmp, idx;
	scanf("%d", &nBlock);

	while(nBlock--){
		for(i=0; i<1005; i++)
			aux[i] = MAX;
		aux[0] = -1;
		curLongest = 1;

		scanf("%d", &N);
		while(N--){
			scanf("%d", &tmp);
			idx = bSearch(aux, tmp, curLongest);
			if(aux[idx] == MAX)
				curLongest = idx;
			aux[idx] = tmp;
		}
		printf("%d\n", curLongest);
		if(nBlock)
			printf("\n");
	}
	return 0;
}
