#include<stdio.h>
#include<math.h>

int main(){
	int N, sum, i, sqt;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d", &N) && N){
		sqt = (int)(sqrt(N));
		sum = 1;
		for(i=2; i<=sqt; i++){
			if(N % i == 0){
				sum += i;
				sum += N/i;
			}
		}
		if(sqt*sqt == N)
			sum -= sqt;
		printf("%5d  ", N);
		if(sum == N)
			printf("PERFECT\n");
		else if(sum > N)
			printf("ABUNDANT\n");
		else
			printf("DEFICIENT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
