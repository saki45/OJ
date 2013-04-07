#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct nodes{
	char ch;
	int count, level, idx;
	bool isLeaf;
	int lc, rc;

	bool operator < (const nodes &a) const{
		return a.count < count;
	}
};

void dfs(nodes node[], int idx, int level){
	node[idx].level = level;
	if(!node[idx].isLeaf){
		if(node[idx].lc >= 0)
			dfs(node, node[idx].lc, level+1);
		if(node[idx].rc >= 0)
			dfs(node, node[idx].rc, level+1);
	}
}

int main(){
	char ch, buf[1500];
	int count[256], pnode;
	nodes node[256], tmp1, tmp2;
	priority_queue<nodes> pq;

	while(fgets(buf, sizeof(buf), stdin)!=NULL && strcmp(buf, "END\n")){
		while(!pq.empty())
			pq.pop();

		memset(count, 0, sizeof(count));
		pnode = 0;

		for(int i=0; buf[i]!='\n'; i++)
			count[(int)(buf[i])]++;
		for(int i=0; i<256; i++){
			if(count[i] > 0){
				node[pnode].ch = (char)i;
				node[pnode].count = count[i];
				node[pnode].level = 0;
				node[pnode].isLeaf = true;
				node[pnode].lc = -1;
				node[pnode].rc = -1;
				node[pnode].idx = pnode;
				pq.push(node[pnode]);
				pnode++;
			}
		}

		int ori_length, new_length=0;
		float t;

		if(pnode == 1){
			ori_length = (strlen(buf)-1)*8;
			new_length = strlen(buf)-1;
			t = ori_length / new_length;
			printf("%d %d %.1f\n", ori_length, new_length, t);
			continue;
		}

		while(pq.size() > 1){
			tmp1 = pq.top();
			pq.pop();
			tmp2 = pq.top();
			pq.pop();
			node[pnode].count = tmp1.count + tmp2.count;
			node[pnode].isLeaf = false;
			node[pnode].lc = tmp1.idx;
			node[pnode].rc = tmp2.idx;
			node[pnode].idx = pnode;
			pq.push(node[pnode]);
			pnode++;
		}

		tmp1 = pq.top();
		pq.pop();
		dfs(node, tmp1.idx, 0);

		ori_length = (strlen(buf)-1)*8;
		for(int i=0; node[i].isLeaf; i++){
			new_length += node[i].count * node[i].level;
		}
		t = ori_length*1.0/new_length;
		printf("%d %d %.1f\n", ori_length, new_length, t);
	}
	return 0;
}
