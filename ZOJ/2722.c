#include<stdio.h>

int getHighestDigit(int N){
	int c = 0;
	while(N > 0){
		c++;
		N = N>>1;
	}
	return c;
}

int main(){
	int N, c;
	scanf("%d", &N);

	while(N > 0){
		if(N == 1)
			printf("0\n");
		else{
			c = getHighestDigit(N);
			if((N&(N-1))==0)
				c--;
			printf("%d\n", c);
		}

		scanf("%d", &N);
	}

	return 0;
}
