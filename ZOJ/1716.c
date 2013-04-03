#include<stdio.h>
#include<string.h>

int main(){
	int N, S, T, W, H, x, y, status[101][101], sum[101][101], i, j, n, tmp;
	scanf("%d", &N);
	while(N){
		memset(status, 0, sizeof(int)*100*100);
		memset(sum, 0, sizeof(int)*100*100);

		scanf("%d%d", &W, &H);
		for(i=0; i<N; i++){
			scanf("%d%d", &x, &y);
			status[x][y] = 1;
		}

		for(i = 1; i<=W; i++){
			for(j = 1; j<=H; j++){
				sum[i][j] = status[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			}
		}

		n = 0;
		scanf("%d%d", &S, &T);
		for(i=S; i<=W; i++){
			for(j=T; j<=H; j++){
				tmp = sum[i][j] - sum[i-S][j] -sum[i][j-T] + sum[i-S][j-T];
				if(n < tmp)
					n = tmp;
			}
		}

		printf("%d\n", n);
		scanf("%d", &N);
	}
	return 0;
}
