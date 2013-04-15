#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct chest{
	int idx;
	int t;
	int keys[26];
	int nKey;

	bool operator < (const chest &a)const{
		if( a.nKey > nKey)
			return true;
		else if(a.nKey == nKey)
			return a.idx < idx;
		else
			return false;
	}
};

int main(){
	freopen("D-small-attempt2.in", "r", stdin);
	//freopen("D-small-attempt2_2.out", "w", stdout);
	chest chs[20], cur;
	priority_queue<chest> pq[26];
	queue<int> q;
	int T, K, N, nCase=1, keys[26], tmp, Ti, Ki, allOpened, curKey, order[20], p;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &K, &N);
		while(!q.empty())
			q.pop();
		for(int i=0; i<=25; i++){
			while(!pq[i].empty())
				pq[i].pop();
		}

		for(int i=0; i<K; i++){
			scanf("%d", &tmp);
			q.push(tmp);
		}

		for(int i=0; i<N; i++){
			scanf("%d%d", &Ti, &Ki);
			chs[i].idx = i+1;
			chs[i].t = Ti;
			chs[i].nKey = Ki;
			memset(chs[i].keys, 0, sizeof(int)*26);
			for(int j=0; j<Ki; j++){
				scanf("%d", &tmp);
				chs[i].keys[tmp]++;
			}
			pq[Ti].push(chs[i]);
		}

		p = 0;
		while(!q.empty()){
			curKey = q.front();
			q.pop();
			if(!pq[curKey].empty()){
				cur = pq[curKey].top();
				order[p++] =cur.idx;
				pq[curKey].pop();
				if(cur.nKey > 0){
					for(int i=0; i<=25; i++){
						while(cur.keys[i]){
							q.push(i);
							cur.keys[i]--;
						}
					}
				}
			}
		}

		allOpened = 1;
		for(int i=0; i<=25; i++){
			if(!pq[i].empty()){
				allOpened = 0;
				break;
			}
		}

		printf("Case #%d:", nCase);
		nCase++;
		if(allOpened){
			for(int i=0; i<p; i++)
				printf(" %d", order[i]);
			printf("\n");
		}
		else{
			printf(" IMPOSSIBLE\n");
		}
	}
	return 0;
}
