#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct chest{
	int idx;
	int t;
	int keys[55];
	int nKey;
	int visited;
};

int remainKeys[55];

int dfs(chest chs[], int keys[], int order[], int require[], int pos, int N){
	if(pos == N)
		return 1;

	for(int k=0; k<55; k++)
		remainKeys[k] = keys[k];
	for(int n=0; n<N; n++){
		if(!chs[n].visited){
			for(int j=0; j<55; j++)
				remainKeys[j] += chs[n].keys[j];
		}
	}
	for(int n=0; n<N; n++){
		if(!chs[n].visited){
			if(remainKeys[chs[n].t] == 0)
				return 0;
			else
				remainKeys[chs[n].t]--;
		}
	}

	for(int k=0; k<55; k++)
		remainKeys[k] = keys[k];
	for(int n=0; n<N; n++){
		if(!chs[n].visited){
			for(int j=0; j<55; j++)
				remainKeys[j] += chs[n].keys[j];
			if(chs[n].keys[chs[n].t])
				remainKeys[chs[n].t]--;
		}
	}

	for(int n=0; n<N; n++){
		if(!chs[n].visited){
			if(!keys[chs[n].t] && !remainKeys[chs[n].t])
				return 0;
		}
	}

	//if(pos)
	//	printf("%d ", order[pos-1]);
	int res;
	for(int n=0; n<N; n++){
		if(!chs[n].visited){
			if(keys[chs[n].t]){
				chs[n].visited = 1;
				keys[chs[n].t]--;
				require[chs[n].t]--;
				order[pos] = chs[n].idx;
				for(int i=0; i<=54; i++)
					keys[i] += chs[n].keys[i];
		
				res = dfs(chs, keys, order, require, pos+1, N);
				if(!res){
					for(int i=0; i<=54; i++)
						keys[i] -= chs[n].keys[i];
					require[chs[n].t]++;
					chs[n].visited = 0;
					keys[chs[n].t]++;
				}
				else
					return 1;
			}
		}
	}
	return 0;
}

int main(){
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	//freopen("test2.in", "r", stdin);
	chest chs[1000];
	int T, K, N, nCase=1, keys[55], tmp, Ti, Ki, res, curKey, order[1000], require[1000], p;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &K, &N);
		memset(keys, 0, sizeof(keys));
		memset(order, 0, sizeof(order));
		memset(require, 0, sizeof(require));

		for(int i=0; i<K; i++){
			scanf("%d", &tmp);
			keys[tmp]++;
		}

		for(int i=0; i<N; i++){
			scanf("%d%d", &Ti, &Ki);
			require[Ti]++;
			chs[i].idx = i+1;
			chs[i].t = Ti;
			chs[i].nKey = Ki;
			chs[i].visited = 0;
			memset(chs[i].keys, 0, sizeof(int)*26);
			for(int j=0; j<Ki; j++){
				scanf("%d", &tmp);
				chs[i].keys[tmp]++;
			}
		}

		res = dfs(chs, keys, order, require, 0, N);

		printf("Case #%d:", nCase);
		nCase++;
		if(res){
			for(int i=0; i<N; i++)
				printf(" %d", order[i]);
			printf("\n");
		}
		else{
			printf(" IMPOSSIBLE\n");
		}
	}
	return 0;
}
