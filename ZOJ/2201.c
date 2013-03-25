#include<stdio.h>

int main(){
	int a, b, N;
	scanf("%d", &N);

	while(N > 0){
		scanf("%d%d", &a, &b);
		if(a<b)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
		N--;
	}
	return 0;
}
