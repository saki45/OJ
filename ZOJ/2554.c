#include<stdio.h>

int main(){
	int N, pts[200000][2], cx, cy, stan, ollie, i;
	double tmp;
	while(scanf("%d", &N) && N){
		for(i=0; i<N; i++)
			scanf("%d%d", &pts[i][0], &pts[i][1]);

		cx = pts[(N-1)/2][0];
		cy = pts[(N-1)/2][1];

		stan = 0;
		ollie = 0;

		for(i=0; i<N; i++){
			tmp = (pts[i][0]-cx)*1.0*(pts[i][1]-cy);
			if(tmp > 0)
				stan++;
			if(tmp < 0)
				ollie++;
		}

		printf("%d %d\n", stan, ollie);
	}
	return 0;
}
