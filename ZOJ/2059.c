#include<stdio.h>
#include<string.h>

#define max(x, y) ((x)>(y)?(x):(y))

int main(){
	int i, j, tmp[2003], dp[2003], N, k;

	while(scanf("%d", &N) && N!=-1){
		for(i=0; i<2003; i++)
			dp[i] = -1;
		dp[0] = 0;
		memcpy(tmp, dp, sizeof(dp));

		for(i=0; i<N; i++){
			scanf("%d", &k);
			for(j=0; j<2003; j++){
				if(dp[j]!=-1){
					tmp[j+k] = max(dp[j], tmp[j+k]);
					if(k < j)
						tmp[j-k] = max(dp[j]+k, tmp[j-k]);
					else
						tmp[k-j] = max(dp[j]+j, tmp[k-j]);
				}		
			}		
			memcpy(dp, tmp, sizeof(dp));
		}
		if(dp[0]!=0)
			printf("%d\n", dp[0]);
		else
			printf("Sorry\n");
	}
	return 0;
}
