#include<stdio.h>

int main(){
	int T, N, sum, base;
	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);
		sum = 0;
		base = 5;
		while(base <= N){
			sum += N/base;
			base *= 5;
		}
		printf("%d\n", sum);
	}
	return 0;
}
