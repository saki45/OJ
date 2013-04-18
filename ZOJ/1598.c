#include<stdio.h>
#include<string.h>

void initboard(int board[][10], int wkr, int wkc){
	memset(board, 0, sizeof(int)*100);
	int i, j;
	for(i=0; i<10; i++){
		board[i][0] = 1;
		board[i][9] = 1;
	}
	for(j=0; j<10; j++){
		board[0][j] = 1;
		board[9][j] = 1;
	}

	for(i=wkr-1; i<=wkr+1; i++)
		for(j = wkc-1; j<=wkc+1; j++)
			board[i][j] = 1;
}

int checkmate(int board[][10], int bkr, int bkc){
	int i, j;
	for(i=bkr-1; i<=bkr+1; i++)
		for(j=bkc-1; j<=bkc+1; j++)
			if(board[i][j] == 0)
				return 0;

	return 1;
}

void setqueen(int board[][10], int qr, int qc, int wkr, int wkc){
	int i, j;
	
	j = qc;
	for(i=qr-1; i>0; i--){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}
	for(i=qr+1; i<9; i++){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}

	i = qr;
	for(j=qc-1; j>0; j--){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}
	for(j=qc+1; j<9; j++){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}

	for(i=qr-1,j=qc-1; i>0&&j>0; i--,j--){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}

	for(i=qr-1,j=qc+1; i>0&&j<9; i--,j++){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}

	for(i=qr+1,j=qc-1; i<9&&j>0; i++,j--){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}

	for(i=qr+1,j=qc+1; i<9&&j<9; i++,j++){
		if(i==wkr && j == wkc)
			break;
		board[i][j] = 1;
	}
}

int process(int board[][10], int wkr, int wkc, int wqr, int wqc, int bkr, int bkc){
	initboard(board, wkr, wkc);
	setqueen(board, wqr, wqc, wkr, wkc);
	return checkmate(board, bkr, bkc);
}

int main(){
	int board[10][10], wkr, wkc, wqr, wqc, bkr, bkc, i, j, qr, qc, found;
	char buf[10], qrr, qrc;
	while(fgets(buf, sizeof(buf), stdin) != NULL){
		wkc = buf[0] - 'a' + 1;
		wkr = buf[1] - '0';
		wqc = buf[3] - 'a' + 1;
		wqr = buf[4] - '0';
		bkc = buf[6] - 'a' + 1;
		bkr = buf[7] - '0';

		found = 0;

		i = wqr;
		for(j=wqc-1; j>0; j--){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}
		for(j=wqc+1; j<9; j++){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}

		j = wqc;
		for(i=wqr-1; i>0; i--){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}
		for(i=wqr+1; i<9; i++){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}

		for(i=wqr-1,j=wqc-1; i>0&&j>0; i--,j--){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}

		for(i=wqr-1,j=wqc+1; i>0&&j<9; i--,j++){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}

		for(i=wqr+1,j=wqc-1; i<9&&j>0; i++,j--){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}

		for(i=wqr+1,j=wqc+1; i<9&&j<9; i++,j++){
			if(i==wkr && j == wkc)
				break;
			if(process(board, wkr, wkc, i, j, bkr, bkc)){
				qr = i;
				qc = j;
				found = 1;
				goto ed;
			}
		}

		ed:
		if(found){
			qrc = qc + 'a' - 1;
			qrr = qr + '0';
			printf("%c%c\n", qrc, qrr);
		}
		else
			printf("no\n");
	}
	return 0;
}
