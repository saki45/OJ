#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

struct nb{
	int r, c, rt;
};

int comp(const void *a, const void *b){
	const struct nb *p1 = a;
	const struct nb *p2 = b;
	return p1->rt - p2->rt;
}

int setStatus(int board[][7], int rt[][7], int nrt[], int N, int M, int r, int c, struct nb nbs[]){
	int i, tr, tc, p, tmp;
	p = 0;
	for(i=0; i<4; i++){
		tr = r+d[i][0];
		tc = c+d[i][1];
		if(tr>=0 && tr<N && tc>=0 && tc<M){
			if(board[tr][tc] == 0){
				tmp = rt[tr][tc];
				rt[tr][tc]--;
				nrt[tmp]--;
				nrt[tmp-1]++;
				nbs[p].r = tr;
				nbs[p].c = tc;
				nbs[p].rt = tmp-1;
				p++;
			}
		}
	}
	return p;
}

void resetStatus(int board[][7], int rt[][7], int nrt[], int N, int M, int r, int c){
	int i, tr, tc, tmp;
	for(i=0; i<4; i++){
		tr = r+d[i][0];
		tc = c+d[i][1];
		if(tr>=0 && tr<N && tc>=0 && tc<M){
			if(board[tr][tc] == 0){
				tmp = rt[tr][tc];
				rt[tr][tc]++;
				nrt[tmp]--;
				nrt[tmp+1]++;
			}
		}
	}
}

int dfs(int board[][7], int rt[][7], int nrt[], int N, int M, int r, int c){
	struct nb nbs[4];
	int i, j, tmp, p, res, sum;
	tmp = rt[r][c];
	nrt[tmp]--;
	board[r][c] = 1;
	if(nrt[1] >= 2){
		nrt[tmp]++;
		board[r][c] = 0;
		return 0;
	}

	p = setStatus(board, rt, nrt, N, M, r, c, nbs);
	sum = 0;
	for(i=0; i<5; i++)
		sum += nrt[i];

	if(p==0 && sum==0){
		return 1;
	}

	if(p==0 || (nrt[0]!=0 && (nrt[1]+nrt[2]+nrt[3]+nrt[4])!=0)){
		resetStatus(board, rt, nrt, N, M, r, c);
		tmp = rt[r][c];
		nrt[tmp]++;
		board[r][c] = 0;
		return 0;
	}
	
	if(p>1)
		qsort(nbs, p, sizeof(struct nb), comp);

	for(i=0; i<p; i++){
		res = dfs(board, rt, nrt, N, M, nbs[i].r, nbs[i].c);
		if(res)
			return 1; 
	}

	resetStatus(board, rt, nrt, N, M, r, c);
	tmp = rt[r][c];
	nrt[tmp]++;
	board[r][c] = 0;
	return 0;
}

int dfs_wrapper(int board[][7], int rt[][7], int nrt[], int N, int M){
	int res = dfs(board, rt, nrt, N, M, 0, 0);
	return res;
}

int main(){
	int M, N, board[7][7], rt[7][7], nrt[5], i, j;
	char ch;
	while(scanf("%d%d", &N, &M) && (M+N)){
		getchar();
		for(i=0; i<N; i++){
			for(j=0; j<M; j++){
				scanf("%c", &ch);
				if(ch=='.')
					board[i][j] = 0;
				else
					board[i][j] = -1;
			}
			getchar();
		}

		memset(nrt, 0, sizeof(nrt));
		memset(rt, 0, sizeof(rt));
		int tmp;
		for(i=0; i<N; i++){
			for(j=0; j<M; j++){
				if(board[i][j]!=0)
					continue;

				tmp = 0;
				if(i>0 && board[i-1][j] == 0)
					tmp++;
				if(i<N-1 && board[i+1][j] == 0)
					tmp++;
				if(j>0 && board[i][j-1] == 0)
					tmp++;
				if(j<M-1 && board[i][j+1] == 0)
					tmp++;
				rt[i][j] = tmp;
				nrt[tmp]++;
			}
		}

		if(nrt[1]>2){
			printf("NO\n");
			continue;
		}

		int sum = 0;
		for(i=1; i<5; i++)
			sum += nrt[i];
		if(nrt[0]>0){
			if(nrt[0] == 1 && sum == 0)
				printf("YES\n");
			else
				printf("NO\n");
			continue;
		}

		if(nrt[0] == 0 && sum == 0){
			printf("YES\n");
			continue;
		}

		int res = dfs_wrapper(board, rt, nrt, N, M);
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
