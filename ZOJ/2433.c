#include<stdio.h>

int main(){
	int N, n, count=1, prev, cur, minDiff, minIdx, i, distance;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &N);
		if(count>1)
			printf("\n");

		if(N<=3){
			printf("0\n");
			for(i=0; i<N-1; i++)
				scanf("%d", &cur);
			continue;
		}

		prev = 0;
		minDiff = 1<<30;
		for(i=2; i<=N; i++){
			scanf("%d", &cur);
			if(cur-prev < minDiff && i>2 && i<N){
				minDiff = cur - prev;
				minIdx = i;
			}
			prev = cur;
		}

		distance = cur + minDiff;
		printf("%d\n", distance);
		printf("%d %d %d %d\n", N, (minIdx-1), minIdx, 1);
		count++;
	}
	return 0;
}
