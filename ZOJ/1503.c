#include<stdio.h>
#include<string.h>

int main(){
	int G, L, DP[31][31], i, j, count=1;
	memset(DP, 0, sizeof(DP));

	for(i=0; i<31; i++){
		DP[i][0] = i;
	}

	for(i=1; i<31; i++){
		for(j=1; j<31; j++){
			DP[i][j] = DP[i-1][j-1] + 1 + DP[i-1][j];
		}
	}

	while(scanf("%d%d", &G, &L) && (G+L)){
		printf("Case %d: %d\n", count++, DP[G][L]);
	}
	return 0;
}
