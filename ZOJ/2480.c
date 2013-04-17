#include<stdio.h>

int main(){
	int w[10][4], M, N, x, y, i, j;
	while(scanf("%d", &N) && N){
		for(i=0; i<N; i++){
			for(j=0; j<4; j++){
				scanf("%d", &w[i][j]);
			}
		}

		scanf("%d", &M);
		for(i=0; i<M; i++){
			scanf("%d%d", &x, &y);
			j = N-1;
			while(j>=0){
				if(w[j][0]<=x && w[j][2]>=x && w[j][1]<=y && w[j][3]>=y)
					break;
				j--;
			}
			printf("%d\n", j);
		}
	}
	return 0;
}
