#include<stdio.h>
#include<string.h>

struct Trie{
	int num;
	int terminal;
	struct Trie *child[10];
};

int insert(struct Trie *buf, int *nodeNum, struct Trie *root, char *s){
	struct Trie *p = root;
	int flag = 0, digit;

	if(*s == '\n')
		return 1;

	while(*s != '\n'){
		digit = *s - '0';
		if(p->child[digit] == NULL){
			p->child[digit] = &buf[*nodeNum];
			*nodeNum += 1;
		}
		else{
			p->child[digit]->num++;
			if(p->child[digit]->terminal && *(s+1)!='\n')
				flag = 1;
		}
		p = p->child[digit];
		s++;
	}
	if(p->terminal != 1){
		p->terminal = 1;
		if(p->num > 1)
			flag = 1;
	}
	return flag;
}

void clearBuf(struct Trie *buf, int *nodeNum){
	int i;
	for(i=0; i<*nodeNum; i++){
		buf->num = 1;
		buf->terminal = 0;
		memset(buf->child, 0, sizeof(struct Trie)*10);
		buf++;
	}
	*nodeNum = 1;
}

int main(){
	int t, i, n, nodeNum, hasConflict;
	scanf("%d", &t);
	struct Trie buf[160000];
	struct Trie *root = buf;
	char strbuf[15];
	nodeNum = 160000;
	while(t--){
		clearBuf(buf, &nodeNum);
		scanf("%d", &n);
		getchar();
		hasConflict = 0;
		for(i=0; i<n; i++){
			fgets(strbuf, sizeof(strbuf), stdin);
			if(!hasConflict && insert(buf, &nodeNum, root, strbuf))
				hasConflict = 1;
		}
		if(!hasConflict)
			printf("YES\n");
		else
			printf("NO\n");
	}	
	return 0;
}
