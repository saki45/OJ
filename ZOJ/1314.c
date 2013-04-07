#include<stdio.h>

int main(){
	int M, N, tmp;
	while(scanf("%d%d", &M, &N)!=EOF){
		printf("%10d%10d", M, N);
		if(M < N){
			tmp = M;
			M = N;
			N = tmp;
		}
		while(N){
			tmp = N;
			N = M%N;
			M = tmp;
		}
		if(M > 1)
			printf("    Bad Choice\n\n");
		else
			printf("    Good Choice\n\n");
	}
	return 0;
}
