#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))

int main(){
	//freopen("test.in", "r", stdin);
	freopen("B-small-attempt1.in", "r", stdin);
	//freopen("A-large.in", "r", stdin);

	freopen("B-small-attempt1.out", "w", stdout);
	//freopen("A-large.out", "w", stdout);

	int T, E, R, N, v[15], nCase, c[13][8], i, n, e, pe, tmp, n1, n2;
	scanf("%d", &T);
	for(nCase=1; nCase<=T; nCase++){
		memset(c, 0, sizeof(c));
		memset(v, 0, sizeof(v));

		scanf("%d%d%d", &E, &R, &N);
		for(i=1; i<=N; i++)
			scanf("%d", &v[i]);

		for(e=0; e<=E; e++)
			c[1][e] = v[1]*(E-e);

		for(n=2; n<=N; n++){
			for(e=0; e<=E; e++){
				for(pe = max(e-R, 0); pe<=E; pe++){
					tmp = min(pe+R, E);
					n1 = c[n][e];
					n2 = c[n-1][pe]+(tmp-e)*v[n];
					//c[n][e] = max(c[n][e], c[n-1][pe]+(tmp-e)*v[i]);
					c[n][e] = max(n1, n2);
				}
			}
		}

		tmp = 0;
		for(e=0; e<=E; e++){
			tmp = max(tmp, c[N][e]);
		}
		printf("Case #%d: %d\n", nCase, tmp);
	}

	return 0;
}
