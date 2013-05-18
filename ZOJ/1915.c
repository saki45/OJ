#include<stdio.h>

int main(){
	int T, N, sum, larger, nums[1002], i;
	double ratio, avg;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		sum = 0;
		for(i=0; i<N; i++){
			scanf("%d", &nums[i]);
			sum += nums[i];
		}

		avg = sum*1.0/N;
		larger = 0;
		for(i=0; i<N; i++)
			if(nums[i] > avg)
				larger++;

		ratio = larger*100.0/N;
		printf("%.3lf\%\n", ratio);
	}
	return 0;
}
