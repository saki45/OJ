#include<stdio.h>
#include<string.h>

int d[11][4] = {{1, 1, 0, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}, {0, 0, 1, 1},
		{0, 1, 0, 1}, {1, 0, 1, 0}, {1, 1, 1, 0}, {1, 1, 0, 1},
		{1, 0, 1, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}};

int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int R, C, G[51][51], count;
char b[55][55];

void dfs(int i, int j){
	G[i][j] = 1;
	int n, idx, ni, nj, nidx;
	idx = b[i][j] - 'A';
	for(n=0; n<4; n++)
		if(d[idx][n]){
			ni = i+direction[n][0];
			nj = j+direction[n][1];
	
			if(ni<0 || ni>=R || nj<0 || nj>=C)
				continue;
			if(G[ni][nj])
				continue;
		
			nidx = b[ni][nj] - 'A';

			if((n & 1) && d[nidx][4-n])
				dfs(ni, nj);
			if(!(n & 1) && d[nidx][2-n])
				dfs(ni, nj);
		}
}

int main(){
	int i, j;
	char buf[55];
	while(scanf("%d%d", &R, &C) && (R+C)>0){
		getchar();
		memset(G, 0, sizeof(G));
		count = 0;
		
		for(i=0; i<R; i++)
			fgets(b[i], sizeof(b[i]), stdin);

		for(i=0; i<R; i++)
			for(j=0; j<C; j++)
				if(G[i][j] == 0){
					count++;
					dfs(i, j);
				}
			
		printf("%d\n", count);
	}
	return 0;
}
