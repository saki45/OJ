#include<string.h>
#include<stdio.h>
#include<math.h>

#define min(X, Y) (X)<(Y) ? (X) : (Y)
#define max(X, Y) (X)>(Y) ? (X) : (Y)

int main(){
	double dp[99*99], dp2[99*99], p, prob;
	double *curr, *prev, *tmp;
	int N, i, j, n, is, js, ti, tj, dd, jst, jed;
	int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while(scanf("%d", &N) != EOF){
		if(N == 1){
			printf("1.0000\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		memset(dp2, 0, sizeof(dp2));
		dp[N/2*99 + N/2] = 1;
		prev = dp;
		curr = dp2;
		prob = 0;
		for(n=0; n<N; n++){
			is = min(n+1, N/2);
			for(i=N/2-is; i<=N/2+is; i++){
				js = n+1 - abs(i-N/2);
				jst = max(0, N/2-js);
				jed = min(N-1, N/2+js);
				for(j=jst; j<=jed; j++){
					curr[i*99+j] = 0;
					for(dd=0; dd<4; dd++){
						ti = i+d[dd][0];
						tj = j+d[dd][1];
						if(ti>=0 && ti<N && tj>=0 && tj<N){
							curr[i*99+j] += prev[ti*99+tj] / (4-(ti==0||ti==N-1)-(tj==0||tj==N-1));
						}
					}
				}
			}
			prob += curr[n*99+N/2];
			curr[n*99+N/2] = 0;
			tmp = curr;
			curr = prev;
			prev = tmp;
		}
		printf("%.4f\n", prob);
	}
	return 0;
}
