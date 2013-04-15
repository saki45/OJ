#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

int match(int a, int b){
	if(a == b)
		return 0;
	else if(a>b)
		return 1;
	else
		return -1;
}

int main(){
	int N, aHorse[1000], bHorse[1000], i, nWin, aFast, aSlow, bFast, bSlow, amount;
	while(scanf("%d", &N) && N){
		for(i=0; i<N; i++)
			scanf("%d", &aHorse[i]);
		for(i=0; i<N; i++)
			scanf("%d", &bHorse[i]);

		nWin = 0;

		qsort(aHorse, N, sizeof(int), compare);
		qsort(bHorse, N, sizeof(int), compare);

		aFast = 0;
		aSlow = N-1;
		bFast = 0;
		bSlow = N-1;
		
		while(aFast <= aSlow){
			if(aHorse[aSlow] > bHorse[bSlow]){
				nWin++;
				aSlow--;
				bSlow--;
			}
			else if(aHorse[aSlow] < bHorse[bSlow]){
				nWin--;
				aSlow--;
				bFast++;
			}
			else{
				if(aHorse[aFast] > bHorse[bFast]){
					nWin++;
					aFast++;
					bFast++;
				}
				else{
					nWin += match(aHorse[aSlow], bHorse[bFast]);
					aSlow--;
					bFast++;

				}
			}
		}
		amount = 200*nWin;
		printf("%d\n", amount);
	}
	return 0;
}
