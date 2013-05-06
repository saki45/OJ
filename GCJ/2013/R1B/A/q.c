#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)>(y)?(x):(y))

int cmp(const void *a, const void *b){
	return (*(int*)a) - (*(int*)b);
}

int main(){
	//freopen("test.in", "r", stdin);
	freopen("A-small-attempt4.in", "r", stdin);
	//freopen("A-large.in", "r", stdin);

	freopen("A-small-attempt4.out", "w", stdout);
	//freopen("A-large.out", "w", stdout);

	int T, nCase, m[102], A, N, adds[102], i, cur, nOp, sumAdds, res[102];
	scanf("%d", &T);
	for(nCase=1; nCase<=T; nCase++){
		memset(adds, 0, sizeof(adds));
		memset(res, 0, sizeof(res));
		scanf("%d%d", &A, &N);

		for(i=0; i<N; i++)
			scanf("%d", &m[i]);

		qsort(m, N, sizeof(int), cmp);

		cur = A;
		nOp = 0;
		if(A == 1){
			printf("Case #%d: %d\n", nCase, N);
			continue;
		}

		for(i=0; i<N; i++){
			if(cur > m[i])
				cur += m[i];
			else if(cur == m[i]){
				adds[i] = 1;
				cur += cur-1;
			}
			else{
				adds[i] = (m[i]-cur)/(cur-1);
				if((m[i]-cur)%(cur-1))
					adds[i]++;
				cur += adds[i]*(cur-1);
			}
		}

		for(i=1; i<N; i++){
			adds[i] += adds[i-1];
		}

		res[0] = adds[0]+N-1;
		res[N-1] = adds[N-1];
		nOp = N;
		for(i=1; i<N-1; i++){
			res[i] = adds[i-1]+N-1-i;
			if(res[i] < nOp)
				nOp = res[i];
		}

		if(res[N-1] < nOp)
			nOp = res[N-1];

		printf("Case #%d: %d\n", nCase, nOp);
	}

	return 0;
}
