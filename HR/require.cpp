#include<cstdio>
#include<cstdlib>

#define MAX 1007

class node{
public:
	int value;
	int *pNext;
	int next_size;
	int *pPrev;
	int prev_size;
	int *pSum;
	bool visited;

	node(int v, int n):value(v), visited(false){
		pNext = (int*)calloc(n, sizeof(int));
		next_size = 0;
		pPrev = (int*)calloc(n, sizeof(int));
		prev_size = 0;
		pSum = (int*)calloc(10, sizeof(int));
	}

	~node(){
		free(pNext);
		free(pPrev);
		free(pSum);
	}

	void addNext(int nextNode){
		for(int i=0; i<next_size; i++){
			if(pNext[i] == nextNode)
				return;
		}
		pNext[next_size++] = nextNode;
	}

	void addPrev(int prevNode){
		for(int i=0; i<prev_size; i++){
			if(pPrev[i] == prevNode)
				return;
		}
		pPrev[prev_size++] = prevNode;
	}
};

void clearVisited(node **nodes, int size){
	for(int i=0; i<size; i++)
		nodes[i]->visited = false;
}

// topological sort
void topSort(node **nodes, int cur, int *order, int &last){
	node *curNode = nodes[cur];
	int tmpNext;
	for(int i=0; i<curNode->next_size; i++){
		tmpNext = curNode->pNext[i];
		if(!nodes[tmpNext]->visited){
			topSort(nodes, tmpNext, order, last);
		}
	}
	curNode->visited = true;
	order[last] = cur;
	last --;
}

int main(){
	int n, m, x, y;
	scanf("%d %d", &n, &m);

	// initialize all nodes
	node **nodes = new node*[n+2];
	for(int i=0; i<n+2; i++){
		nodes[i] = new node(i, n+2);
	}

	// process global source([0]) and sink([n+1])
	// add two links from each node to source and sink
	for(int i=1; i<n+1; i++){
		nodes[0]->addNext(i);
		nodes[n+1]->addPrev(i);
		nodes[i]->addPrev(0);
		nodes[i]->addNext(n+1);
	}

	// now in our program the first element is 1 instead of 0
	// add the requirements to build a graph
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		if(x >= y)
			continue;
		nodes[x+1]->addNext(y+1);
		nodes[y+1]->addPrev(x+1);
	}

	int *order = (int*)calloc(n+2, sizeof(int));
	int last = n+1;
	topSort(nodes, 0, order, last);

	// set initial value for source
	for(int i=0; i<10; i++){
		nodes[0]->pSum[i] = 1;
	}

	// process each node according to the order from topsort
	int thisNode, thisSum;
	for(int i=1; i<n+2; i++){
		thisNode = order[i];
		nodes[thisNode]->pSum[0] = 
	}

	// delete all the nodes
	for(int i=0; i<n+2; i++){
		delete nodes[i];
	}
	delete[] nodes;
	free(order);
}
