#include<stdio.h>
#include<string.h>

#define MAXSIZE 32770
#define MIN(x, y) (x)<(y)?(x):(y)

int main(){
	int p, i, dp[MAXSIZE][4], n, p2, ed;
	memset(dp, 0, sizeof(dp));

	for(p=1; p<182; p++){
		if(p*p < MAXSIZE)
			dp[p*p][0] = 1;
	}

	for(p=1; p<182; p++){
		for(n=1; n<4; n++){
			p2 = p*p;
			ed = MIN(MAXSIZE, p2*n);
			for(i=0; i<=ed; i++){
				if(i+p2 < MAXSIZE && dp[i][n-1]!=0)
					dp[i+p2][n] += dp[i][n-1];
			}
		}
	}
	while(scanf("%d", &n) && n){
		p = dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3];
		printf("%d\n", p);
	}
	return 0;
}
