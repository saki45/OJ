#include<stdio.h>

int main(){
	int cMin, cMax, cur, T, n, i, dis;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		cMin = 101;
		cMax = -1;
		for(i=0; i<n; i++){
			scanf("%d", &cur);
			if(cur < cMin)
				cMin = cur;
			if(cur > cMax)
				cMax = cur;
		}
		dis = (cMax - cMin)<<1;
		printf("%d\n", dis);
	}
	return 0;
}
