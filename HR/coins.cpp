#include<cstdio>
#include<queue>

using namespace std;

int main(){
	int n, m, k;
	scanf("%d %d %d\n", &n, &m, &k);

	int b[n][m];
	int targetX, targetY;
	char ch;

	for(int row=0; row<n; row++){
		for(int col=0; col<m; col++){
			scanf("%c", &ch);
			switch(ch){
				case '*':
					targetX = row;
					targetY = col;
					b[row][col] = 0;
					break;
				case 'U':
					b[row][col] = 1;
					break;
				case 'R':
					b[row][col] = 2;
					break;
				case 'D':
					b[row][col] = 3;
					break;
				case 'L':
					b[row][col] = 4;
					break;
			}
		}
		scanf("%c", &ch);
	}

	for(int row=0; row<n; row++){
		for(int col=0; col<m; col++)
			printf("%d ", b[row][col]);
		printf("\n");
	}

	if(targetX + targetY > k){
		printf("-1\n");
		return 0;
	}

	int dx[] = {0, 0, 1, 0, -1};
	int dy[] = {0, 1, 0, -1, 0};

	int time[n][m], label[n][m]; 
	for(int row=0; row<n; row++){
		for(int col=0; col<m; col++){
			label[row][col] = -1;
			time[row][col] = n+m+1;
		}
	}
}
