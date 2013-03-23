#include<stdio.h>

int main(){
	int R[101][101], G[101][101], B[101][101], avg[101][101], N, M, row, col;
	int count = 1;

	while(1){
		scanf("%d%d", &N, &M);
		if(N == 0 && M == 0)
			break;
		for(row = 0; row<N; row++)
			for(col = 0; col<M; col++)
				scanf("%d", &R[row][col]);

		for(row = 0; row<N; row++)
			for(col = 0; col<M; col++)
				scanf("%d", &G[row][col]);

		for(row = 0; row<N; row++)
			for(col = 0; col<M; col++)
				scanf("%d", &B[row][col]);
		
		for(row = 0; row<N; row++)
			for(col = 0; col<M; col++){
				avg[row][col] = (R[row][col] + G[row][col] + B[row][col]) / 3;
			}
		printf("Case %d:\n", count);
		count++;
		for(row = 0; row<N; row++){
			for(col = 0; col<M-1; col++)
				printf("%d,", avg[row][col]);
			printf("%d\n", avg[row][M-1]);
		}	
	}

	return 0;
}
