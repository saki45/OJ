#include<stdio.h>
#include<string.h>

int main(){
	int i, j, b[21][21], tmp, t, ni, nj, hasWin, wr, wc, n, s;
	int direction[4][2] = {{-1, 1}, {0, 1}, {1, 1}, {1, 0}};
	scanf("%d", &t);
	while(t--){
		memset(b, 0, sizeof(b));
		hasWin = 0;
		for(i=1; i<20; i++)
			for(j=1; j<20; j++)
				scanf("%d", &b[i][j]);

		for(i=1; i<20; i++){
			for(j=1; j<20; j++){
				if(b[i][j] == 0)
					continue;
				tmp = b[i][j];
				for(n=0; n<4; n++){
					ni = i - direction[n][0];
					nj = j - direction[n][1];
					if(b[ni][nj] == tmp)
						continue;
					for(s=1; s<6; s++){
						ni = i + direction[n][0]*s;
						nj = j + direction[n][1]*s;
						if(ni<1 || ni>19 || nj<1 || nj>19)
							break;
						if(b[ni][nj] != tmp)
							break;
					}
					if(s == 5){
						hasWin = tmp;
						wr = i;
						wc = j;
						goto Win;
					}
				}
			}
		}
		Win:
		if(hasWin){
			printf("%d\n%d %d\n", hasWin, wr, wc);
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
