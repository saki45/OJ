#include<stdio.h>
#include<math.h>

int main(){
	int i, N, T;
	double logSum;

	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);
		
		if(N==0){
			printf("1\n");
			continue;
		}

		logSum = 0;
		for(i=1; i<=N; i++)
			logSum += log10((double)i);
		
		N = (int)logSum + 1;
		printf("%d\n", N);
	}
	return 0;
}
