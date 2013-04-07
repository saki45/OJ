#include<stdio.h>
#include<string.h>

#define MAXN 50
#define MAXDIGIT 200

struct node{
	int visited;
	int neighbor[MAXN];
	int nN;
	int isIn;
};

struct bigNumber{
	int num[MAXDIGIT];
	int c;
};

void clearBigNumber(struct bigNumber *bn){
	bn->c = 0;
	memset(bn->num, 0, sizeof(int)*MAXDIGIT);
}

void multiply(struct bigNumber *a, struct bigNumber *b, struct bigNumber *c){
	clearBigNumber(c);
	int i, j, ca, cb, cc, *buf;
	ca = a->c;
	cb = b->c;
	buf = c->num;

	for(i=0; i<ca; i++)
		for(j=0; j<cb; j++)
			buf[i+j] += a->num[i] * b->num[j];

	for(i=0; i<ca+cb-1; i++){
		if(buf[i] >= 10){
			buf[i+1] += buf[i]/10;
			buf[i] = buf[i] % 10;
		}
	}

	c->c = buf[ca+cb-1]>0?ca+cb:ca+cb-1;		
}

void dfs(struct node nodes[], int n){
	if(!nodes[n].visited){
		nodes[n].visited = 1;
		int i, next;
		for(i=0; i<nodes[n].nN; i++){
			next = nodes[n].neighbor[i];
			if(!nodes[next].visited){
				nodes[next].isIn = 1;
				dfs(nodes, next);
			}
		}
	}
}

void setNum(struct bigNumber *a, int n){
	int i=0;
	while(n){
		a->num[i++] = n%10;
		n /= 10;
	}
	a->c = i;
}

void copyBigNumber(struct bigNumber *src, struct bigNumber *dst){
	dst->c = src->c;
	int i;
	for(i=0; i<src->c; i++)
		dst->num[i] = src->num[i];
}

int main(){
	int M, N, u, v, i, tmp;
	struct bigNumber a, b, c;
	struct node nodes[MAXN];

	while(scanf("%d%d", &N, &M)!=EOF && (M+N)){
		for(i=0; i<N; i++){
			nodes[i].visited = 0;
			nodes[i].nN = 0;
			nodes[i].isIn = 0;
			memset(nodes[i].neighbor, 0, sizeof(nodes[i].neighbor));
		}

		for(i=1; i<N; i++){
			scanf("%d%d", &u, &v);
			nodes[u-1].neighbor[nodes[u-1].nN] = v-1;
			nodes[u-1].nN ++;
			nodes[v-1].neighbor[nodes[v-1].nN] = u-1;
			nodes[v-1].nN ++;
		}

		dfs(nodes, 0);

		tmp = M;
		if(nodes[0].isIn)
			tmp--;
		clearBigNumber(&a);
		setNum(&a, tmp);

		for(i=1; i<N; i++){
			tmp = M;
			if(nodes[i].isIn)
				tmp--;
			clearBigNumber(&b);
			setNum(&b, tmp);
			multiply(&a, &b, &c);
			copyBigNumber(&c, &a);
		}

		if(a.c == 0)
			printf("0\n");
		else{
			for(i=a.c-1; i>=0; i--)
				printf("%d", a.num[i]);
			printf("\n");
		}
	}
	return 0;
}
