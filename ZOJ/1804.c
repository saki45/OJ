#include<stdio.h>
#include<string.h>

int main(){
	int board[21][21], pos[11][2], rCount[21], cCount[21], n, r, c, i, j, rTmp, cTmp, nCase, d, td, count, id;
	char buf[30];

	nCase = 1;

	while(scanf("%d%d", &r, &c) && (r+c)){
		memset(board, 0, sizeof(board));
		memset(pos, 0, sizeof(pos));
		memset(rCount, 0, sizeof(rCount));
		memset(cCount, 0, sizeof(cCount));

		scanf("%d", &n);
		for(i=1; i<=n; i++){
			scanf("%d%d", &rTmp, &cTmp);
			pos[i][0] = rTmp;
			pos[i][1] = cTmp;
			rCount[rTmp]++;
			cCount[cTmp]++;
			board[rTmp][cTmp] = i;
		}

		while(scanf("%s", buf) && strcmp(buf, "done") != 0){
			scanf("%d", &d);
			if(strcmp(buf, "down") == 0){
				for(i=0; i<c; i++)
					if(d > r-cCount[i])
						d = r-cCount[i];
				for(j=0; j<c; j++){
					count = 0;
					for(i=0; i<d; i++)
						if(board[i][j] != 0)
							count++;
					if(count==0)
						continue;
					for(i=d; i<r; i++){
						if(board[i][j] == 0)
							count--;
						if(count == 0)
							break;
					}
					td = i;
					for(i=td-1; td>=d; i--){
						if(board[i][j] != 0){
							board[td][j] = board[i][j];
							board[i][j] = 0;
							id = board[td][j];
							pos[id][0] = td;
							pos[id][1] = j;
							rCount[td]++;
							rCount[i]--;
							td--;
							
						}
					}
				}
			}
			if(strcmp(buf, "up") == 0){
				for(i=0; i<c; i++)
					if(d > r-cCount[i])
						d = r-cCount[i];
				for(j=0; j<c; j++){
					count = 0;
					for(i=r-1; i>r-1-d; i--)
						if(board[i][j] != 0)
							count++;
					if(count==0)
						continue;
					for(i=r-1-d; i>=0; i--){
						if(board[i][j] == 0)
							count--;
						if(count == 0)
							break;
					}
					td = i;
					for(i=td+1; td<=r-1-d; i++){
						if(board[i][j] != 0){
							board[td][j] = board[i][j];
							board[i][j] = 0;
							id = board[td][j];
							pos[id][0] = td;
							pos[id][1] = j;
							rCount[td]++;
							rCount[i]--;
							td++;
							
						}
					}
				}
			}
			if(strcmp(buf, "right") == 0){
				for(i=0; i<r; i++)
					if(d > c-rCount[i])
						d = c-rCount[i];
				for(i=0; i<r; i++){
					count = 0;
					for(j=0; j<d; j++)
						if(board[i][j] != 0)
							count++;
					if(count==0)
						continue;
					for(j=d; j<c; j++){
						if(board[i][j] == 0)
							count--;
						if(count == 0)
							break;
					}
					td = j;
					for(j=td-1; td>=d; j--){
						if(board[i][j] != 0){
							board[i][td] = board[i][j];
							board[i][j] = 0;
							id = board[i][td];
							pos[id][0] = i;
							pos[id][1] = td;
							cCount[td]++;
							cCount[j]--;
							td--;	
						}
					}
				}
			}
			if(strcmp(buf, "left") == 0){
				for(i=0; i<r; i++)
					if(d > c-rCount[i])
						d = c-rCount[i];
				for(i=0; i<r; i++){
					count = 0;
					for(j=c-1; j>c-1-d; j--)
						if(board[i][j] != 0)
							count++;
					if(count==0)
						continue;
					for(j=c-1-d; j>=0; j--){
						if(board[i][j] == 0)
							count--;
						if(count == 0)
							break;
					}
					td = j;
					for(j=td+1; td<=c-1-d; j++){
						if(board[i][j] != 0){
							board[i][td] = board[i][j];
							board[i][j] = 0;
							id = board[i][td];
							pos[id][0] = i;
							pos[id][1] = td;
							cCount[td]++;
							cCount[j]--;
							td++;	
						}
					}
				}
			}
		}

		printf("Data set %d ends with boxes at locations", nCase++);
		for(i=0; i<r;i++)
			for(j=0; j<c; j++)
				if(board[i][j])
					printf(" (%d,%d)", i, j);
		printf(".\n");
	}
	return 0;
}
