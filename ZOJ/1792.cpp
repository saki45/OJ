//WA

#include<cstdio>
#include<cstring>

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int N, la, lb, i, j, dp0[502][502], dp1[502][502], dp2[502][502], tmp;
	char a[502], b[502];
	scanf("%d", &N);
	while(N--){
		scanf("%s%s", a, b);
		la = strlen(a);
		lb = strlen(b);

		memset(dp0, 0, sizeof(dp0));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));

		for(i=1; i<=la; i++)
			dp2[i][0] = -(4+i);
		
		for(j=1; j<=lb; j++)
			dp1[0][j] = -(4+j);
	
		for(i=1; i<=la; i++){
			for(j=1; j<=lb; j++){
				int t = a[i-1]==b[j-1]?2:-1;
				dp0[i][j] = max(dp0[i-1][j-1]+t, max(dp1[i-1][j-1]+t, dp2[i-1][j-1]+t));
				dp1[i][j] = max(dp1[i-1][j]-1, max(dp0[i][j-1]-5, dp0[i-1][j]-5));
				dp2[i][j] = max(dp2[i][j-1]-1, max(dp0[i][j-1]-5, dp0[i-1][j]-5));
			}
		}
		tmp = max(dp0[la][lb], max(dp1[la][lb], dp2[la][lb]));
		printf("%d\n", tmp);
	}
	return 0;
}
