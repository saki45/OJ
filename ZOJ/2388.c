#include<stdio.h>

int main(){
	int N, sum ,diff, a, b;
	scanf("%d", &N);
	while(N--){
		scanf("%d%d", &sum, &diff);
		if(sum < diff)
			printf("impossible\n");
		else{
			if((sum+diff)%2 || (sum-diff)%2)
				printf("impossible\n");
			else{
				a = (sum+diff)/2;
				b = (sum-diff)/2;
				printf("%d %d\n", a, b);
			}
		}
	}
	return 0;
}
