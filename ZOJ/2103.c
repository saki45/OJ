#include<stdio.h>
#include<string.h>

#define min(x, y) ((x)<(y)?(x):(y))



void dfs_connect_recur(int G[][10], int visited[], int cur, int M){
	int i;
	visited[cur] = 1;
	for(i=0; i<M; i++){
		if(G[cur][i]!=-1 && visited[i]==0)
			dfs_connect_recur(G, visited, i, M);
	}
}

int dfs_connect(int G[][10], int visited[], int M){
	int res = 1, i;
	dfs_connect_recur(G, visited, 0, M);
	for(i=0; i<M; i++){
		if(visited[i] == 0){
			res = 0;
			break;
		}
	}
	return res;
}

void dfs(int G[][10], int cur, int path[], int *p, int H, int *now, int *best, int odd, int M){
	if(*p == H){
		if(odd == 0 && path[0]==path[H-1])
			*best = min(*best, (*now)-1);
		else
			*best = min(*best, *now);
		return;
	}

	int i;
	for(i=0; i<M; i++){
		if(G[cur][i] != -1){
			if((*p>0) && path[(*p)-1] != G[cur][i]){
				(*now)++;
			}
			path[(*p)] = G[cur][i];
			(*p)++;
			G[cur][i] = -1;
			G[i][cur] = -1;
			dfs(G, i, path, p, H, now, best, odd, M);
			(*p)--;
			G[cur][i] = path[*p];
			G[i][cur] = G[cur][i];
			if((*p)>0 && path[(*p)+1]!=path[(*p)])
				(*now)--;
		}
	}

}

int main(){
	int G[10][10], M, C, H, h, i, j, visited[10], deg[10], odd, tmp, st, path[20], p, now, best;
	while(scanf("%d%d%d", &M, &C, &H) && (M+C+H)){
		memset(G, -1, sizeof(G));
		for(h=0; h<H; h++){
			scanf("%d%d%d", &i, &j, &tmp);
			G[i][j] = tmp;
			G[j][i] = tmp;
		}

		odd = 0;
		memset(deg, 0, sizeof(deg));
		for(i=0; i<M; i++){
			for(j=0; j<M; j++)
				if(G[i][j] != -1)
					deg[i]++;
			if(deg[i] & 1)
				odd++;
		}

		if(!(odd==0 || odd==2)){
			printf("No\n");
			continue;
		}	

		memset(visited, 0, sizeof(visited));
		tmp = dfs_connect(G, visited, M);
		if(tmp == 0){
			printf("No\n");
			continue;
		}

		if(odd == 2){
			for(i=0; i<M; i++)
				if(deg[i] & 1){
					st = i;
					break;
				}
		}
		else{
			st = 0;
		}

		memset(path, -1, sizeof(path));
		p = 0;
		now = 0;
		best = 25;
		dfs(G, st, path, &p, H, &now, &best, odd, M);

		if(best == 25)
			printf("No\n");
		else
			printf("%d\n", best);		
	}
	return 0;
}
