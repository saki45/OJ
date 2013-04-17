#include<stdio.h>

int main(){
	int N, i, j, sum, d;
	char ch;
	scanf("%d", &N);
	getchar();
	while(N--){
		for(i=0; i<4; i++){
			sum = 0;
			for(j=0; j<8; j++){
				scanf("%c", &ch);
				d = ch - '0';
				sum = (sum<<1) + d;
			}
			printf("%d", sum);
			if(i<3)
				printf(".");
			else
				printf("\n");
		}
		getchar();
	}
	return 0;
}
