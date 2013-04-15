#include<stdio.h>
#include<string.h>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXNUM 220

int main(){
	int coins[6], p, i, j, dp[MAXNUM], curMax, sum, N, tCoin, nMin;
	double avg;
	scanf("%d", &N);
	while(N--){
		for(i=0; i<6; i++)
			scanf("%d", &coins[i]);

		memset(dp, 1, sizeof(dp));

		dp[0] = 0;
		for(j=0; j<20; j++){
			for(p=0; p<6; p++){
				tCoin = coins[p];
				for(i=0; i<MAXNUM; i++){
					if(i+tCoin <= 200)
						dp[i+tCoin] = MIN(dp[i+tCoin], dp[i]+1);
					if(i-tCoin > 0)
						dp[i-tCoin] = MIN(dp[i-tCoin], dp[i]+1);
				}
			}
		}

		sum = 0;
		curMax = 0;
		for(i=1; i<=100; i++){
			sum += dp[i];
			if(dp[i] > curMax)
				curMax = dp[i];
		}
		avg = sum / 100.0;
		printf("%.2lf %d\n", avg, curMax);
	}
	return 0;
}
