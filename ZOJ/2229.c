#include<stdio.h>
#include<math.h>
#define MAX 99999999

int main(){
	int N, spd, st, i, ans;
	double cur, curMin;

	while(scanf("%d", &N) && N){
		curMin = MAX;
		for(i=0; i<N; i++){
			scanf("%d%d", &spd, &st);
			if(st >= 0){
				cur = 4.5*3600/(double)spd+st;
				if(cur < curMin)
					curMin = cur;
			}
		}
		
		ans = ceil(curMin);
		printf("%d\n", ans);
	}
	return 0;
}
