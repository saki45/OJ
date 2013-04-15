#include<stdio.h>
#include<stdlib.h>

struct shirt{
	double sum;
	int idx;
};

int comp(const void *p1, const void *p2){
	const struct shirt *pp1 = p1;
	const struct shirt *pp2 = p2;
	if(pp1->sum > pp2->sum)
		return -1;
	else if(pp2->sum == pp1->sum){
		return pp1->idx - pp2->idx;
	}
	else
		return 1;
}

int comp2(const void *p1, const void *p2){
	const struct shirt *pp1 = p1;
	const struct shirt *pp2 = p2;
	return pp2->idx - pp1->idx;
}

int main(){
	int N, M, K, i, n;
	double tmp;
	struct shirt st[10010];
	while(scanf("%d%d%d", &N, &M, &K) != EOF){
		for(i=0; i<M; i++){
			st[i].sum = 0;
			st[i].idx = i+1;
		}

		for(n=0; n<N; n++){
			for(i=0; i<M; i++){
				scanf("%lf", &tmp);
				st[i].sum += tmp;
			}
		}

		qsort(st, M, sizeof(struct shirt), comp);
		qsort(st, K, sizeof(struct shirt), comp2);

		for(i=0; i<K-1; i++)
			printf("%d ", st[i].idx);
		printf("%d\n", st[K-1].idx);
	}
	return 0;
}
