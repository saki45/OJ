#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b){
	return *(int*)b - *(int*)a;
}

int main(){
	int T, N, curMax, nums[1001], i, tmp;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(i=0; i<N; i++)
			scanf("%d", &nums[i]);

		qsort(nums, N, sizeof(int), comp);
		curMax = 0;
		for(i=0; i<N; i++){
			tmp = nums[i]*(i+1);
			if(tmp > curMax)
				curMax = tmp;
		}
		printf("%d\n", curMax);
	}
	return 0;
}
