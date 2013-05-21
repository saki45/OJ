#include<stdio.h>
#include<string.h>

#define min(X,Y) ((X)<(Y)?(X):(Y))

void draw(char board[][78], int y, int x, char ch){
	if(board[y][x] == '*')
		return;

	char ori = board[y][x];
	if(ori == ' ' || ori == ch)
		board[y][x] = ch;
	else{
		if((ori=='+' && (ch=='-' || ch=='|')) || (ori=='-' && ch=='|') || (ori=='|' && ch=='-'))
			board[y][x] = '+';
		else if((ori=='x' && (ch=='/' || ch=='\\')) || (ori=='\\' && ch=='/') || (ori=='/' && ch=='\\'))
			board[y][x] = 'x';
		else
			board[y][x] = '*';
	}
}

int main(){
	char board[78][78], txt[77], cmd[10], ch;
	int R, C, x1, y1, x2, y2, x, y, tmp;
	while(scanf("%d%d", &C, &R) && R*C){
		memset(board, ' ', sizeof(board));
		for(x=0; x<=C+1; x++){
			draw(board, 0, x, '-');
			draw(board, R+1, x, '-');
		}
		for(y=0; y<=R+1; y++){
			draw(board, y, 0, '|');
			draw(board, y, C+1, '|');
		}

		while(scanf("%s", cmd) && strcmp(cmd, "PRINT")){
			if(strcmp(cmd, "LINE") == 0){
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				if(x1 == x2){
					if(y1>y2){
						tmp = y2;
						y2 = y1;
						y1 = tmp;
					}
					for(y=y1; y<=y2; y++)
						draw(board, y, x1, '|');
				}
				else if(y1 == y2){
					if(x1>x2){
						tmp = x2;
						x2 = x1;
						x1 = tmp;
					}
					for(x=x1; x<=x2; x++)
						draw(board, y1, x, '-');
				}
				else{
					if(y1>y2){
						tmp = y2;
						y2 = y1;
						y1 = tmp;
						tmp = x2;
						x2 = x1;
						x1 = tmp;
					}
					if(x1 < x2){
						ch = '\\';
						for(x=x1, y=y1; x<=x2, y<=y2; x++, y++)
							draw(board, y, x, ch);
					}
					else{
						ch = '/';
						for(x=x1, y=y1; x>=x2, y<=y2; x--, y++)
							draw(board, y, x, ch);
					}
				}
			}
			else if(strcmp(cmd, "CLEAR") == 0){
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				if(y1 > y2){
					tmp = y2;
					y2 = y1;
					y1 = tmp;
				}
				if(x1>x2){
					tmp = x2;
					x2 = x1;
					x1 = tmp;
				}
				for(x=x1; x<=x2; x++)
					for(y=y1; y<=y2; y++)
						board[y][x] = ' ';
			}
			else if(strcmp(cmd, "POINT") == 0){
				scanf("%d%d", &x1, &y1);
				draw(board, y1, x1, 'o');
			}
			else{
				scanf("%d%d %s", &x1, &y1, txt);
				for(x=x1; x<=min(C, strlen(txt)+x1-1); x++)
					draw(board, y1, x, txt[x-x1]);
			}
		}
		for(y=0; y<=R+1; y++){
			board[y][C+2] = '\0';
			printf("%s\n", board[y]);
		}
		printf("\n");
	}
	
	return 0;
}
