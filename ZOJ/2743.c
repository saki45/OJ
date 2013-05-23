// Should be Hexagon instead of square, don't want to change though

#include<string.h>
#include<stdio.h>

int board[105][105], count, H, W, h, w;
int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void canReachTop(int r, int c){
	int n;
	if(r<0 || r>=H || c<0 || c>=W)
		return;
	if(board[r][c]==0)
		return;
	
	board[r][c] = 0;
	for(n=0; n<8; n++){
		canReachTop(r+direction[n][0], c+direction[n][1]);
	}
}

void dfs(int r, int c, int color){
	int n;
	if(r<0 || r>=H || c<0 || c>=W)
		return;
	if(color != board[r][c])
		return;
	
	count++;
	board[r][c] = 0;
	for(n=0; n<8; n++)
		dfs(r+direction[n][0], c+direction[n][1], color);
}

int main(){
	char buf[107];
	int i, j;
	while(scanf("%d%d%d%d", &H, &W, &h, &w)!=EOF){
		h--;
		w--;
		memset(board, 0, sizeof(board));
		getchar();
		for(i=0; i<H; i++){
			fgets(buf, sizeof(buf), stdin);
			for(j=0; buf[j]!='\n'; j++){
				if(buf[j]!='E')
					board[i][j] = buf[j]-'a'+1;
			}
		}
		count = 0;
		dfs(h, w, board[h][w]);
		if(count>=3){
			for(i=0; i<W; i++){
				if(board[0][i])
					canReachTop(0, i);
			}
			for(i=0; i<H; i++)
				for(j=0; j<W; j++)
					if(board[i][j])
						count++;
			printf("%d\n", count);
		}
		else
			printf("0\n");
	}
	return 0;
}
