#include<stdio.h>
#include<string.h>

int main(){
	int T, board[255][255], count[5], sum, i, j, R, C, hash[256], j2;
	char buf[255];
	scanf("%d", &T);

	memset(hash, 0, sizeof(hash));
	hash['J'] = 1;
	hash['H'] = 2;
	hash['Y'] = 3;
	hash['N'] = 4;

	while(T--){
		scanf("%d%d", &R, &C);
		sum = 0;
		for(i=0; i<R; i++){
			scanf("%s", buf);
			for(j=0; j<C; j++){
				board[i][j] = hash[buf[j]];
			}
		}

		for(j=0; j<C-1; j++){
			for(j2=j+1; j2<C; j2++){
				memset(count, 0, sizeof(count));
				for(i=0; i<R; i++)
					if(board[i][j] == board[i][j2])
						count[board[i][j]]++;
				for(i=0; i<5; i++){
					if(count[i]>=2)
						sum += count[i]*(count[i]-1)/2;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
