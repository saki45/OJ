#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>

using namespace std;

struct nodes{
	int r, c, s;
	bool operator < (const nodes &n) const{
		return s < n.s;
	}
};

int main(){
	int T, M, N, K, p, curTime, sum, tmps, canDoNext, firstValid, dis;
	nodes node[2501], tmp, ntmp;
	priority_queue<nodes> pq;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &M, &N, &K);
		p = 0;
		curTime = 0;
		sum = 0;
		while(pq.size() > 0)
			pq.pop();
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				scanf("%d", &tmps);
				if(tmps){
					node[p].r = i;
					node[p].c = j;
					node[p].s = tmps;
					pq.push(node[p]);
					p++;
				}
			}
		}

		canDoNext = 1;
		firstValid = 0;
		/*
		while(!firstValid && pq.size()>0){
			tmp = pq.top();
			pq.pop();
			if(2*(tmp.r+1)+1 <= K){
				firstValid = 1;
				curTime += tmp.r+2;
				sum += tmp.s;
			}
		}

		if(!firstValid){
			printf("0\n");
			continue;
		}
		*/

		tmp = pq.top();
		pq.pop();
		if(2*tmp.r+3 > K){
			printf("0\n");
			continue;
		}
		curTime += tmp.r+2;
		sum += tmp.s;

		while(canDoNext && pq.size()>0){
			ntmp = pq.top();
			pq.pop();

			dis = abs(tmp.r-ntmp.r) + abs(tmp.c-ntmp.c);
			if(curTime + dis + 1 + ntmp.r + 1 <= K){
				curTime += dis + 1;
				sum += ntmp.s;
				tmp = ntmp;
			}
			else
				canDoNext = 0;
		}
		printf("%d\n", sum);
	}
	return 0;
}
