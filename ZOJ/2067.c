#include<stdio.h>
#include<string.h>

#define min(x, y) ((x)<(y)?(x):(y))

int main(){
	int board[101][101], right[101][101], i, j, N, res, r, c, tmp;
	char ch;
	while(scanf("%d", &N) != EOF){
		memset(board, 0, sizeof(board));
		memset(right, 0, sizeof(right));
		getchar();
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				scanf("%c", &ch);
				if(ch == '#')
					board[i][j] = 1;
				if(ch == '.')
					board[i][j] = 0;
			}
			getchar();
		}

		for(i=1; i<=N; i++){
			right[i][N] = 0;
			for(j=N-1; j>=1; j--){
				if(board[i][j] == 0){
					if(board[i][j+1] == 0)
						right[i][j] = right[i][j+1]+1;
				}
			}
		}

		res = 0;
		for(i=1; i<=N; i++){
			for(j=1; j<=N; j++){
				if(board[i][j] == 0){
					res += right[i][j]+1;
					c = 1;
					r = right[i][j];
					while(board[i+c][j] == 0 && i+c <= N){
						r = min(r, right[i+c][j]);
						res += r+1;
						c++;
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
