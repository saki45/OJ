#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct card{
	int v, a;
}c[13];

int cmp(const void *a, const void *b){
	const struct card *pa = a;
	const struct card *pb = b;
	return pb->v - pa->v;
}

int M, N, count, sum[15];

void dfs(int r, int p){
	if(r == 0){
		count++;
		return;
	}
	if(p >= M)
		return;
	if(sum[p] < r)
		return;
	if(sum[p] == r){
		count++;
		return;
	}

	int i;
	for(i=0; i<=c[p].a; i++){
		if(r-i*c[p].v >=0)
			dfs(r-i*c[p].v, p+1);
		else
			break;
	}
}

int main(){
	int i, isFirst=1;
	while(scanf("%d%d", &N, &M)!=EOF){
		if(!isFirst)
			printf("\n");
		if(isFirst)
			isFirst = 0;

		memset(sum, 0, sizeof(sum));
		memset(c, 0, sizeof(c));

		for(i=0; i<M; i++){
			scanf("%d%d", &c[i].v, &c[i].a);
			sum[i] = c[i].v*c[i].a;
		}

		qsort(c, M, sizeof(struct card), cmp);

		for(i=M-2; i>=0; i--)
			sum[i] += sum[i+1];

		count = 0;
		dfs(N, 0);

		printf("%d\n", count);
	}
	return 0;
}
