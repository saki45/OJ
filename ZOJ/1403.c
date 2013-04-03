#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2){
	return *((char*)p2) - *((char*)p1);
}

int solve(int *ans, int N, int nums[][6], int *selected, int i, int p, int len){
	if(p&1)
		N += nums[i][p+1];
	else
		N -= nums[i][p+1];

	selected[i] = 1;
	ans[p] = nums[i][1];
	int j, res;
	if(p == 4){
		if(N == 0)
			return 1;
		ans[p] = 0;
		selected[i] = 0;
		return 0;
	}
	for(j=0; j<len; j++){
		if(!selected[j]){
			res = solve(ans, N, nums, selected, j, p+1, len);
			if(res)
				return 1;
		}
	}
	selected[i] = 0;
	ans[p] = 0;
	return 0;
}

int main(){
	int nums[12][6], ans[5], i, j, sum, N, len, res, selected[15];
	char buf[15], ch;
	scanf("%d", &N);
	while(N != 0){
		getchar();
		scanf("%s", buf);
		len = strlen(buf);
		qsort(buf, len, sizeof(char), cmp);

		for(i=0; i<len; i++)
			nums[i][1] = buf[i]-'A'+1;
		for(i=0; i<len; i++)
			for(j=2; j<=5; j++)
				nums[i][j] = nums[i][j-1] * nums[i][1];

		memset(ans, 0, 5*sizeof(int));
		memset(selected, 0, 15*sizeof(int));
		for(i=0; i<len; i++){
			res = solve(ans, N, nums, selected, i, 0, len);
			if(res)
				break;
		}

		if(res){
			for(i=0; i<5; i++){
				ch = ans[i] + 'A' - 1;
				printf("%c", ch);
			}
			printf("\n");
		}
		else
			printf("no solution\n");

		scanf("%d", &N);
	}
	return 0;
}
