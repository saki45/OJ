#include<stdio.h>

int main(){
	double cur, prev, diff;

	scanf("%lf", &prev);
	if((int)prev == 999){
		printf("End of Output\n");
	}
	else{
		scanf("%lf", &cur);
		if((int)cur == 999){
			printf("End of Output\n");
		}
		else{
			diff = cur - prev;
			printf("%.2f\n", diff);
			prev = cur;
			scanf("%lf", &cur);
			while((int)cur != 999){
				diff = cur - prev;
				printf("%.2f\n", diff);
				prev = cur;
				scanf("%lf", &cur);
			}
			printf("End of Output\n");
		}
	}
	return 0;
}
