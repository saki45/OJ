#include<stdlib.h>
#include<stdio.h>

int cmp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

int main(){
	int T, n, i, sum, a[20001];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(int), cmp);
		sum = 0;
		for(i=2; i<n; i+=3){
			sum += a[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
