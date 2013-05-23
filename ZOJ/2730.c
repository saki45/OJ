#include<stdio.h>
#include<string.h>

int adj[50][50], N, sol[1200], status[50], p;

int dfs(int n){
	int numOfNext=0, numOfIncomplete, i, j, prev = sol[n-1], next, reachLast, res;
	for(i=0; i<N; i++){
		if(adj[prev][i] == 0){
			numOfNext++;
			next = i;
		}
	}

	if(numOfNext == 0)
		return 0;
	if(numOfNext == 1){
		numOfIncomplete = 0;
		reachLast = 1;
		for(i=0; i<N; i++){
			if(status[i]<=N-3){
				reachLast = 0;
				break;
			}
			if(status[i]==N-2){
				numOfIncomplete++;
				if(numOfIncomplete>2){
					reachLast = 0;
					break;
				}
			}
		}

		if(reachLast && sol[0]==next){
			return 1;
		}
		else if(reachLast)
			return 0;
	}
	
	for(i=0; i<N; i++){
		if(adj[prev][i]==0){
			adj[prev][i] = 1;
			adj[i][prev] = 1;
			status[prev]++;
			status[i]++;
			sol[p++] = i;
			res = dfs(n+1);
			if(res)
				return 1;
			else{
				adj[i][prev] = 0;
				adj[prev][i] = 0;
				status[i]--;
				status[prev]--;
				p--;
			}
		}
	}
	return 0;
}

int main(){
	int i;
	while(scanf("%d", &N) != EOF){
		p = 1;
		memset(adj, 0, sizeof(adj));
		memset(status, 0, sizeof(status));

		for(i=0; i<N; i++)
			adj[i][i] = 1;

		sol[0] = 0;
		dfs(1);

		printf("%d\n", p);
		for(i=0; i<p-1; i++)
			printf("%d ", sol[i]);
		printf("%d\n", sol[p-1]);
	}
	return 0;
}
