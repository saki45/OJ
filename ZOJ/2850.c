#include<stdio.h>

int main(){
	int N, M, board[10][10], i, j, hasNoGrass, hasAdj;

	scanf("%d%d", &N, &M);
	while(N!=0 && M!=0){
		hasNoGrass = 0;
		hasAdj = 0;
		for(i=0; i<N; i++){
			for(j=0; j<M; j++){
				scanf("%d", &board[i][j]);
				if(board[i][j] == 0){
					hasNoGrass = 1;
					if(i>0 && board[i-1][j] == 0)
						hasAdj = 1;
					if(j>0 && board[i][j-1] == 0)
						hasAdj = 1;
				}
			}
		}
		if(!hasNoGrass || hasAdj)
			printf("No\n");
		else
			printf("Yes\n");
		scanf("%d%d", &N, &M);
	}

	return 0;
}
