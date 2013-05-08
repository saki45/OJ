#include<stdio.h>

int main(){
	int f0, f1, f2, f3, f4, f5, A, B, C;
	while(scanf("%d%d%d", &f0, &f1, &f2) != EOF){
		C = f0;
		A = (f2 - 2*f1+ C)/2;
		B = f1 - A - C;

		f3 = 9*A + 3*B + C;
		f4 = 16*A + 4*B + C;
		f5 = 25*A + 5*B + C;

		printf("%d %d %d\n", f3, f4, f5);
	}
	return 0;
}
