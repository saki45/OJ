#include<stdio.h>
#include<string.h>

#define max(x, y) (x)>(y)?(x):(y)

void update(int board[][100], int visited[][100], int rMin[], int rMax[], int cMin[], int cMax[], int rClear[], int cClear[], int N, int M){
	int i, j;

	for(i=0; i<N; i++){
		rMin[i] = 200;
		rMax[i] = 0;
	}
	for(i=0; i<M; i++){
		cMin[i] = 200;
		cMax[i] = 0;
	}

	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			if(!rClear[i] && !cClear[j]){
				if(rMin[i] > board[i][j])
					rMin[i] = board[i][j];
				if(rMax[i] < board[i][j])
					rMax[i] = board[i][j];
				if(cMin[j] > board[i][j])
					cMin[j] = board[i][j];
				if(cMax[j] < board[i][j])
					cMax[j] = board[i][j];
			}
		}
	}

	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			if(visited[i][j]){
				if(board[i][j] > rMin[i])
					rMax[i] = max(rMax[i], board[i][j]);
				if(board[i][j] > cMin[j])
					cMax[j] = max(cMax[j], board[i][j]);
			}
		}
	}
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	int ncase, N, M, board[100][100], visited[100][100], rMin[100], rMax[100], cMin[100], cMax[100], rClear[100], cClear[100];
	int caseNum = 1, i, j, tmp, nClear, rsolved, csolved;
	scanf("%d", &ncase);

	while(ncase--){
		scanf("%d%d", &N, &M);

		memset(board, 0, sizeof(board));
		memset(visited, 0, sizeof(visited));
		memset(rMax, 0, sizeof(rMax));
		memset(cMax, 0, sizeof(cMax));
		memset(rClear, 0, sizeof(rClear));
		memset(cClear, 0, sizeof(cClear));

		for(i=0; i<100; i++){
			rMin[i] = 200;
			cMin[i] = 200;
		}

		for(i=0; i<N; i++){
			for(j=0; j<M; j++){
				scanf("%d", &tmp);
				if(rMin[i] > tmp)
					rMin[i] = tmp;
				if(rMax[i] < tmp)
					rMax[i] = tmp;
				if(cMin[j] > tmp)
					cMin[j] = tmp;
				if(cMax[j] < tmp)
					cMax[j] = tmp;
				board[i][j] = tmp;
			}
		}

		do{
			nClear = 0;
			for(i=0; i<N; i++){
				if(rMin[i] == rMax[i] && !rClear[i]){
					for(j=0; j<M; j++)
						visited[i][j] = 1;
					rClear[i] = 1;
					nClear ++;
				}
			}

			for(j=0; j<M; j++){
				if(cMin[j] == cMax[j] && !cClear[j]){
					for(i=0; i<N; i++)
						visited[i][j] = 1;
					cClear[j] = 1;
					nClear ++;
				}
			}

			update(board, visited, rMin, rMax, cMin, cMax, rClear, cClear, N, M);

		}while(nClear);

		rsolved = 1;
		for(i=0; i<N; i++){
			if(!rClear[i])
				rsolved = 0;
		}
		csolved = 1;
		for(j=0; j<M; j++){
			if(!cClear[j])
				csolved = 0;
		}

		printf("Case #%d: ", caseNum);
		caseNum++;

		if(rsolved || csolved){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}
