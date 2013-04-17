#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int N, A[100], i, cur;
	while(scanf("%d", &N) && N){
		for(i=0; i<N; i++){
			scanf("%d", &A[i]);
		}

		qsort(A, N, sizeof(int), comp);
		cur = A[0];
		printf("%d", cur);
		for(i=1; i<N; i++){
			if(A[i] == cur)
				continue;
			else{
				cur = A[i];
				printf(" %d", cur);
			}
		}
		printf("\n");
	}
	return 0;
}
