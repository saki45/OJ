#include<stdio.h>
#include<string.h>

int dfs(int cards[][4], int num[], int board[], int N, int count, int pos){
	int x=pos/N, y=pos%N, p, res, rValid, cValid, nIdx;
	if(pos == N*N)
		return 1;
	res = 0;
	for(p=0; p<count; p++){
		if(num[p] == 0)
			continue;
		rValid = x>0?0:1;
		cValid = y>0?0:1;
		if(x>0){
			nIdx = board[(x-1)*N + y];
			if(cards[p][0] == cards[nIdx][2])
				rValid = 1;
		}
		if(!rValid)
			continue;

		if(y>0){
			nIdx = board[x*N+y-1];
			if(cards[p][3] == cards[nIdx][1])
				cValid = 1;
		}
		if(!cValid)
			continue;

		board[pos] = p;
		num[p]--;
		res = dfs(cards, num, board, N, count, pos+1);
		if(res)
			return 1;
		else{
			board[pos] = 0;
			num[p]++;
		}
	}
	return 0;
}

int main(){
	int cards[25][4], num[25], board[25], N, N2, nCount=0, i, j, count, res;
	while(scanf("%d", &N) && N){
		N2 = N*N;
		count = 0;
		memset(cards, 0, sizeof(cards));
		memset(num, 0, sizeof(num));
		memset(board, 0, sizeof(board));

		for(j=0; j<N2; j++){
			for(i=0; i<4; i++)
				scanf("%d", &cards[24][i]);
			for(i=0; i<count; i++)
				if(cards[i][0] == cards[24][0] && cards[i][1] == cards[24][1] && cards[i][2] == cards[24][2] && cards[i][3] == cards[24][3])
					break;
			if(i==count){
				for(i=0; i<4; i++)
					cards[count][i] = cards[24][i];
				num[count] = 1;
				count++;
			}
			else{
				num[i]++;
			}
		}

		res = dfs(cards, num, board, N, count, 0);
		if(nCount++)
			printf("\n");
		printf("Game %d: ", nCount);
		if(res)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0;
}
