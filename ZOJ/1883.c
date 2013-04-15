#include<stdio.h>
#include<string.h>

int main(){
	int n, k, i, j;
	double dp[10][102], sum;
	while(scanf("%d%d", &k, &n) != EOF){
		memset(dp, 0, sizeof(dp));

		for(i=0; i<=k; i++)
			dp[i][1] = 1;
		for(j=2; j<=n; j++){
			for(i=0; i<=k; i++){
				dp[i][j] += dp[i][j-1];
				if(i>0)
					dp[i][j] += dp[i-1][j-1];
				if(i<k)
					dp[i][j] += dp[i+1][j-1];
			}
		}

		sum = 0;
		for(i=0; i<=k; i++)
			sum += dp[i][n];
		for(j=1; j<=n; j++)
			sum /= (double)(k+1);
		sum *= 100;
		printf("%0.5lf\n", sum);

	}
	return 0;
}
