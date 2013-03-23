#include<stdio.h>

int main(){
	int N, num, i;
	scanf("%d", &N);
	while(N>0){

		scanf("%d", &num);
		i = 0;
		while(num > 0){
			if(num & 1 != 0){
				printf("%d", i);
			}
			if(num & (num-1) != 0)
				printf(" ");
			num = num>>1;
			i++;
		}
		printf("\n");

		N--;
	}
}
