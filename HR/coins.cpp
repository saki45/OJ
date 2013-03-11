#include<cstdio>
#include<queue>
#include<cstdlib>

using namespace std;

struct point{
	int x;
	int y;
	int time;
	int label;
};

void setPoint(point *p, int x, int y, int label, int time){
	p->x = x;
	p->y = y;
	p->label = label;
	p->time = time;
}

int main(){
	int n, m, k;
	scanf("%d %d %d\n", &n, &m, &k);

	int b[n][m];
	int targetX, targetY;
	char ch;

	// read in the whole graph
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


	// if the target is too far away then just return -1
	if(targetX + targetY > k){
		printf("-1\n");
		return 0;
	}

	// store the four directions
	int dx[] = {0, -1, 0, 1, 0};
	int dy[] = {0, 0, 1, 0, -1};

	// originally the label is -1(unvisited) and time is n*m (larger than the largest possibility)
	int time[n][m], label[n][m]; 
	for(int row=0; row<n; row++){
		for(int col=0; col<m; col++){
			label[row][col] = -1;
			time[row][col] = n*m;
		}
	}

	// init of the two queues, set the first starting point to be (0, 0), with label 0 and time 0
	std::queue<point*> stQ, pathQ;
	point *pSt = (point*)malloc(sizeof(point));
	setPoint(pSt, 0, 0, 0, 0);
	stQ.push(pSt);

	bool isReached = false, hasPath;
	int curX, curY, nextX, nextY, curTime, curLabel;

	while(!isReached){
		// find the next start point
		pSt = stQ.front();
		curX = pSt->x;
		curY = pSt->y;
		curTime = pSt->time;
		curLabel = pSt->label;

		stQ.pop();
		free(pSt);
		
		//printf("st: (%d, %d) t=%d l=%d \n", curX, curY, curTime, curLabel);
		if(b[curX][curY] == 0){
			isReached = true;
			// free the allocated spaces
			while(!stQ.empty()){
				pSt = stQ.front();
				stQ.pop();
				free(pSt);
			}
			while(!pathQ.empty()){
				pSt = pathQ.front();
				pathQ.pop();
				free(pSt);
			}
			printf("%d\n", curLabel);
			return 0;
		}

		// if the time from this point is larger than the current start point then we can start from here
		if(curTime < time[curX][curY]){
			hasPath = true;

			// proceed until we cannot make a move
			while(hasPath){
				time[curX][curY] = curTime;
				label[curX][curY] = curLabel;

				//printf("(%d, %d) t=%d l=%d \n", curX, curY, curTime, curLabel);
				if(curTime == k)
					break;

				// check the next move
				nextX = curX + dx[b[curX][curY]];
				nextY = curY + dy[b[curX][curY]];

				// going out of bounds
				if(nextX<0 || nextX>=n || nextY<0 || nextY>=m){
					hasPath = false;
				}
				// find target
				else if(b[nextX][nextY] == 0){
					isReached = true;
					// free the allocated spaces
					while(!stQ.empty()){
						pSt = stQ.front();
						stQ.pop();
						free(pSt);
					}
					while(!pathQ.empty()){
						pSt = pathQ.front();
						pathQ.pop();
						free(pSt);
					}

					printf("%d\n", curLabel);
					return 0;
				}
				// will not go to earlier points
				else if(time[nextX][nextY] <= curTime+1){
					hasPath = false;
				}
				// next point is valud, proceed to the next point
				
				// if time limit is not reached, put the current point into pathQ, and proceed to next
				if(curTime < k){
					pSt = (point*)malloc(sizeof(point));
					setPoint(pSt, curX, curY, curLabel, curTime);
					pathQ.push(pSt);
					curX = nextX;
					curY = nextY;
					curTime ++;
				}
			}

			/*
			for(int row=0; row<n; row++){
				for(int col=0; col<m; col++)
					printf("%d ", time[row][col]);
				printf("\n");
			}*/
			// by the end of the current search, we need to:
			// 1. clearn the current path
			// 2. add new starting point from the neighbors of the current path
			while(!pathQ.empty()){
				pSt = pathQ.front();
				pathQ.pop();

				curX = pSt->x;
				curY = pSt->y;
				curTime = pSt->time;
				curLabel = pSt->label;

				//printf("poped: (%d, %d) t=%d l=%d \n", curX, curY, curTime, curLabel);
				// search for the four neighbors of an point in the path to check whether it could be set as the new starting point
				for(int i=1; i<=4; i++){
					nextX = curX + dx[i];
					nextY = curY + dy[i];

					// if the neighbor is in bound
					if(nextX>=0 && nextX<n && nextY>=0 && nextY<m){
						// if the time in the neighbor is larger than curTime+1 then it could be regarded as a new starting point.
						if(time[nextX][nextY] > curTime + 1){
							pSt = (point*)malloc(sizeof(point));
							//printf("(%d, %d)eq: (%d, %d) t=%d l=%d \n", curX, curY, nextX, nextY, curTime+1, curLabel+1);
							setPoint(pSt, nextX, nextY, curLabel+1, curTime+1);
							stQ.push(pSt);
						}
					}
				}
			}
		}
	}
	// free the allocated spaces
	while(!stQ.empty()){
		pSt = stQ.front();
		stQ.pop();
		free(pSt);
	}
	while(!pathQ.empty()){
		pSt = pathQ.front();
		pathQ.pop();
		free(pSt);
	}
}
