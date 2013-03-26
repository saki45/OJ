#include<stdio.h>

int main(){
	int N, sum ,spd, time, nTime;
	scanf("%d", &N);
	while(N>0){
		sum = 0;
		time = 0;
		while(N--){
			scanf("%d%d", &spd, &nTime);
			sum += spd*(nTime - time);
			time = nTime;
		}
		printf("%d miles\n", sum);
		scanf("%d", &N);
	}
	return 0;
}
