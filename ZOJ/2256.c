#include<stdio.h>

int main(){
	int N;
	double price;
	while(scanf("%d", &N) && N){
		if(N <= 4)
			price = 10;
		else if(N<=8)
			price = 10 + (N-4)*2;
		else{
			if(N % 8 < 5){
				price = (N/8)*18 + 2.4*(N%8);
			}
			else{
				price = (N/8)*18 + 2*(N%8-4) + 10;
			}
		}
		if((int)price == price)
			printf("%d\n", ((int)(price)));
		else
			printf("%.1f\n", price);
	}
	return 0;
}
