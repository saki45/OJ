#include<stdio.h>
#include<string.h>

#define max(x, y) (x)>(y)?(x):(y)

void convert(int a[], int len, char buf[]){
	int i;
	for(i=1; i<=len; i++){
		switch(buf[i-1]){
			case 'A':
				a[i] = 1;
				break;
			case 'C':
				a[i] = 2;
				break;
			case 'G':
				a[i] = 3;
				break;
			case 'T':
				a[i] = 4;
				break;
		}
	}
}

int main(){
	int dp[102][102], a[101], b[101], i, j, N, la, lb, res;
	int c[5][5] = {0, -3, -4, -2, -1, -3, 5, -1, -2, -1, -4, -1, 5, -3, -2, -2, -2, -3, 5, -2, -1, -1, -2, -2, 5};
	char buf[105];
	a[0] = 0;
	b[0] = 0;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &la);
		getchar();
		scanf("%s", buf);
		convert(a, la, buf);

		scanf("%d", &lb);
		getchar();
		scanf("%s", buf);
		convert(b, lb, buf);

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 0;
		for(i=1; i<=la; i++)
			dp[i][0] = dp[i-1][0] + c[0][a[i]];
		for(i=1; i<=lb; i++)
			dp[0][i] = dp[0][i-1] + c[0][b[i]];

		for(i=1; i<=la; i++){
			for(j=1; j<=lb; j++){
				res = dp[i-1][j-1] + c[a[i]][b[j]];
				res = max(res, dp[i][j-1] + c[0][b[j]]);
				res = max(res, dp[i-1][j] + c[0][a[i]]);
				dp[i][j] = res;
			}
		}
		printf("%d\n", dp[la][lb]);
	}
	return 0;
}
