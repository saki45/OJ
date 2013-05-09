#include<stdio.h>

int main(){
	int curFloor, nFloor, N, time;
	while(scanf("%d", &N) && N){
		curFloor = 0;
		time = 0;
		while(N--){
			scanf("%d", &nFloor);
			if(nFloor > curFloor)
				time += (nFloor-curFloor)*6;
			if(nFloor < curFloor)
				time += (curFloor-nFloor)*4;
			time += 5;
			curFloor = nFloor;
		}
		printf("%d\n", time);
	}
	return 0;
}
