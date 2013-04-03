#include<stdio.h>
#include<string.h>
#include<math.h>
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )

int main(){
	int M, N1, N2, a[101], b[101], f1[101][101], f2[101][101], f[101][101], i, j, prev, tmp;
	scanf("%d", &M);
	while(M--){
		scanf("%d%d", &N1, &N2);
		memset(a, 0, sizeof(int)*(N1+1));
		memset(b, 0, sizeof(int)*(N2+1));

		for(i=1; i<=N1; i++)
			scanf("%d", &a[i]);
		for(j=1; j<=N2; j++)
			scanf("%d", &b[j]);

		memset(f1, 0, sizeof(int)*101*101);
		memset(f2, 0, sizeof(int)*101*101);
		memset(f, 0, sizeof(int)*101*101);
		
		for(i=1; i<=N1; i++){
			prev = -1;
			for(j=1; j<=N2; j++){
				if(b[j] == a[i]){
					prev = j;
				}
				if(prev > 0)
					f1[i][j] = prev;
			}
		}

		for(i=1; i<=N2; i++){
			prev = -1;
			for(j=1; j<=N1; j++){
				if(b[i] == a[j]){
					prev = j;
				}
				if(prev > 0)
					f2[i][j] = prev;
			}
		}

		for(i=1; i<=N1; i++){
			for(j=1; j<=N2; j++){
				tmp = max(f[i-1][j], f[i][j-1]);
				if(a[i] != b[j] && f1[i][j-1] > 0 && f2[j][i-1] > 0)
					tmp = max(tmp, f[f2[j][i-1]-1][f1[i][j-1]-1]+2);
				f[i][j] = tmp;
			}
		}

		printf("%d\n", f[N1][N2]);
	}
	return 0;
}
