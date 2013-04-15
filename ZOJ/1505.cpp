// This code is WA

#include<cstdio>
#include<cstring>
#include<queue>
#include<set>

using namespace std;

int boardToStatus(int board[][8]){
	int ns = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(board[i][j]){
				ns = ns*10 + i;
				ns = ns*10 + j;
			}
		}
	}
	return ns;
}

int getNextStatus(int status, int board[][8], int next[], int pt[]){
	int nStatus = 0, ns, tx, ty;
	for(int i=7; i>=0; i--){
		pt[i] = status%10;
		status /= 10;
	}
	for(int i=0; i<4; i++){
		board[pt[2*i]][pt[2*i+1]] = 1;
	}

	for(int i=0; i<4; i++){
		tx = pt[2*i];
		ty = pt[2*i+1];

		if(tx > 0){
			if(board[tx-1][ty] == 0){
				board[tx][ty] = 0;
				board[tx-1][ty] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx-1][ty] = 0;
				board[tx][ty] = 1;
			}
			else if(tx > 1 && board[tx-2][ty] == 0){
				board[tx][ty] = 0;
				board[tx-2][ty] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx-2][ty] = 0;
				board[tx][ty] = 1;
			}
		}
		if(tx < 7){
			if(board[tx+1][ty] == 0){
				board[tx][ty] = 0;
				board[tx+1][ty] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx+1][ty] = 0;
				board[tx][ty] = 1;
			}
			else if(tx < 6 && board[tx+2][ty] == 0){
				board[tx][ty] = 0;
				board[tx+2][ty] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx+2][ty] = 0;
				board[tx][ty] = 1;
			}

		}
		if(ty > 0){
			if(board[tx][ty-1] == 0){
				board[tx][ty] = 0;
				board[tx][ty-1] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx][ty-1] = 0;
				board[tx][ty] = 1;
			}
			else if(ty > 1 && board[tx][ty-2] == 0){
				board[tx][ty] = 0;
				board[tx][ty-2] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx][ty-2] = 0;
				board[tx][ty] = 1;
			}

		}
		if(ty < 7){
			if(board[tx][ty+1] == 0){
				board[tx][ty] = 0;
				board[tx][ty+1] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx][ty+1] = 0;
				board[tx][ty] = 1;
			}
			else if(ty < 6 && board[tx][ty+2] == 0){
				board[tx][ty] = 0;
				board[tx][ty+2] = 1;
				next[nStatus++] = boardToStatus(board);
				board[tx][ty+2] = 0;
				board[tx][ty] = 1;
			}

		}
	}
	

	for(int i=0; i<4; i++){
		board[pt[2*i]][pt[2*i+1]] = 0;
	}

	return nStatus;
}

int main(){
	queue<int> qf, qb;
	set<int> sf, sb;
	int fp[8], bp[8], board[8][8], fs, bs, found, round, ftlevel, fnlevel, btlevel, bnlevel;
	int fnext[16], fnnext, bnext[16], bnnext;
	while(scanf("%d", &fp[0]) != EOF){
		memset(board, 0, sizeof(board));

		if(!sf.empty())
			sf.erase(sf.begin(), sf.end());
		if(!sb.empty())
			sb.erase(sb.begin(), sb.end());
		while(!qf.empty())
			qf.pop();
		while(!qb.empty())
			qb.pop();

		for(int i=1; i<8; i++)
			scanf("%d", &fp[i]);
		for(int i=0; i<8; i++)
			scanf("%d", &bp[i]);
		for(int i=0; i<4; i++){
			board[fp[2*i]][fp[2*i+1]] = 1;
		}
		fs = boardToStatus(board);
		for(int i=0; i<4; i++){
			board[fp[2*i]][fp[2*i+1]] = 0;
		}
		for(int i=0; i<4; i++){
			board[bp[2*i]][bp[2*i+1]] = 1;
		}
		bs = boardToStatus(board);
		for(int i=0; i<4; i++){
			board[bp[2*i]][bp[2*i+1]] = 0;
		}
		found = fs==bs;
		if(found){
			printf("YES\n");
			continue;
		}

		round = 0;
		sf.insert(fs);
		sb.insert(bs);
		qf.push(fs);
		qb.push(bs);
		ftlevel = 1;
		btlevel = 1;
		while(round < 4 && !found){
			fnlevel = 0;
			while(ftlevel>0 && !found){
				fs = qf.front();
				qf.pop();
				fnnext = getNextStatus(fs, board, fnext, fp);
				for(int i=0; i<fnnext; i++){
					if(sb.count(fnext[i]))
						found = 1;
					else{
						if(!sf.count(fnext[i])){
							qf.push(fnext[i]);
							sf.insert(fnext[i]);
							fnlevel++;
						}
					}
				}
				ftlevel--;
			}
			ftlevel = fnlevel;
			if(round == 4)
				break;

			bnlevel = 0;
			while(btlevel>0 && !found){
				bs = qb.front();
				qb.pop();
				bnnext = getNextStatus(bs, board, bnext, bp);
				for(int i=0; i<bnnext; i++){
					if(sf.count(bnext[i]))
						found = 1;
					else{
						if(!sb.count(bnext[i])){
							qb.push(bnext[i]);
							sb.insert(bnext[i]);
							bnlevel++;
						}
					}
				}
				btlevel--;
			}
			btlevel = bnlevel;
			round++;
		}

		if(found)
			printf("YES\n");
		else
			printf("No\n");
	}
	return 0;
}
