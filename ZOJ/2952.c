#include<stdio.h>
#include<stdlib.h>

typedef long long LL;
#define MAXNUM 2147483648LL

int cmp(const void *a, const void *b){
	const LL ta = *((LL*)a);
	const LL tb = *((LL*)b);

	if(ta < tb)
		return -1;
	else if(ta > tb)
		return 1;
	else
		return 0;
}

int main(){
	LL nums[100000], n, M, cur, i, j, k;

	n = 0;
	for(M=2; M*M < MAXNUM; M++){
		cur = M*M;
		while(cur < MAXNUM){
			nums[n++] = cur;
			cur *= M;
		}
	}

	qsort(nums, n, sizeof(LL), cmp);

	i = 0;
	j = 0;
	k = 0;
	while(i < n){
		j = i;
		while(nums[j] == nums[i])
			j++;
		nums[k++] = nums[i];
		i = j;
	}

	n = k;

	for(cur=0; cur<n; cur++){
		printf("%Ld\n", nums[cur]);
	}

	return 0;
}
