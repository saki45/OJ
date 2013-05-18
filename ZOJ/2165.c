#include<stdio.h>
#include<string.h>

int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int G[][22], int W, int H, int i, int j, int *count){
	if(i<0 || i>=W || j<0 || j>=H)
		return;
	if(G[i][j] == 0)
		return;

	(*count)++;
	G[i][j] = 0;
	int k;
	for(k=0; k<4; k++)
		dfs(G, W, H, i+direction[k][0], j+direction[k][1], count);
}

int main(){
	int W, H, G[22][22], r, c, count, i, j;
	char buf[24];

	while(scanf("%d%d", &H, &W) && (W+H)){
		for(i=0; i<W; i++){
			scanf("%s", buf);
			for(j=0; j<H; j++){
				switch(buf[j]){
					case '.':
						G[i][j] = 1;
						break;
					case '@':
						G[i][j] = 1;
						r = i;
						c = j;
						break;
					case '#':
						G[i][j] = 0;
				}
			}
		}

		count = 0;
		dfs(G, W, H, r, c, &count);
		printf("%d\n", count);
	}
	return 0;
}
