#include<stdio.h>
#include<string.h>

#define max(X,Y) ((X)>(Y)?(X):(Y))

int shift[8], sum[8][8], G[8][8], N, curMax;

void dfs(int l){
	int i, j, sumMax, s=shift[l];
	if(l>0){
		sumMax = 0;
		for(i=0; i<N; i++){
			sum[l][(i+s)%N] = sum[l-1][i] + G[l][(i+s)%N];
			sumMax = max(sumMax, sum[l][(i+s)%N]);
		}
		if(sumMax > curMax)
			return;
	}

	if(l==N-1){
		if(sumMax < curMax)
			curMax = sumMax;
		return;
	}

	for(i=0; i<N; i++){
		shift[l+1] = i;
		dfs(l+1);
	}
}

int main(){
	int i, j;
	while(scanf("%d", &N) && N>0){
		memset(shift, 0, sizeof(shift));
		memset(sum, 0, sizeof(sum));
		memset(G, 0, sizeof(G));
		curMax = 0;

		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				scanf("%d", &G[i][j]);
				if(i==0)
					sum[i][j] = G[i][j];
				else
					sum[i][j] = sum[i-1][j]+G[i][j];
			}
		}

		for(j=0; j<N; j++)
			curMax = max(curMax, sum[N-1][j]);

		if(N==1){
			printf("%d\n", curMax);
			continue;
		}

		dfs(0);
		printf("%d\n", curMax);
	}

	return 0;
}
