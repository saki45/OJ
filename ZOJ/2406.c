#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define min(X, Y) ((X)<(Y)?(X):(Y))

int NV, NR, SV, DV, maxDist, pRes, G[21][21], visited[21], path[21];

struct res{
	int dist, pl;
	int path[20];
};
struct res r[50];

int cmp(const void *a, const void *b){
	const struct res *pa = a;
	const struct res *pb = b;
	if(pa->dist != pb->dist)
		return pa->dist - pb->dist;
	else{
		int i, l=min(pa->pl, pb->pl);
		for(i=0; i<l; i++){
			if(pa->path[i] != pb->path[i])
				return pa->path[i] - pb->path[i];
		}
		return pa->pl - pb->pl;
	}
}

void dfs(int cur, int pPath, int curDist){
	path[pPath] = cur;
	if(cur == DV){
		r[pRes].dist = curDist;
		r[pRes].pl = pPath+1;
		int i, j=0, tmp, digit;
		for(i=0; i<=pPath; i++){
			r[pRes].path[i] = path[i];
		}
		pRes++;
		return;
	}

	visited[cur] = 1;
	int i;
	for(i=1; i<=NV; i++){
		if(visited[i] == 0 && G[cur][i]>0 && curDist+G[cur][i]<=maxDist){
			dfs(i, pPath+1, curDist+G[cur][i]);
		}
	}

	visited[cur] = 0;
}

int main(){
	int i, j, rr, cc, tmp, nCase=1, isFirst=1;
	while(scanf("%d", &NV) && NV>0){
		if(nCase!=1)
			isFirst = 0;
		if(!isFirst)
			printf("\n");

		scanf("%d", &NR);
		memset(G, 0, sizeof(G));
		memset(visited, 0, sizeof(visited));
		memset(path, 0, sizeof(path));
		pRes = 0;

		for(i=0; i<NR; i++){
			scanf("%d%d%d", &rr, &cc, &tmp);
			G[rr][cc] = tmp;
			G[cc][rr] = tmp;
		}

		scanf("%d%d%d", &SV, &DV, &maxDist);

		dfs(SV, 0, 0);

		qsort(r, pRes, sizeof(struct res), cmp);
		printf("Case %d:\n", nCase++);
		for(i=0; i<pRes; i++){
			printf(" %d:", r[i].dist);
			for(j=0; j<r[i].pl; j++)
				printf(" %d", r[i].path[j]);
			printf("\n");
		}
	}
	return 0;
}
