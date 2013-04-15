#include<stdio.h>
#include<string.h>

int main(){
	int sum[102], a[102], p[102], dp[102], c, i, j, tmp, N;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &c);
		sum[0] = 0;
		for(i=1; i<=c; i++){
			scanf("%d%d", &a[i], &p[i]);
			sum[i] = sum[i-1] + a[i];
		}

		memset(dp, 0, sizeof(dp));
		for(i=1; i<=c; i++){
			dp[i] = dp[i-1]+(a[i]+10)*p[i];
			for(j=i-2; j>=0; j--){
				tmp = dp[j] + (sum[i]-sum[j]+10)*p[i];
				if(tmp < dp[i])
					dp[i] = tmp;
			}
		}
		printf("%d\n", dp[c]);
	}
	return 0;
}
