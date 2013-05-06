#include<stdio.h>

int getGCD(int a, int b){
	int tmp;
	if(a < b){
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b>0){
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main(){
	int T, N, tmp, n1, n2, gcd;

	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		if(N == 1){
			scanf("%d", &n1);
			printf("%d\n", n1);
			continue;
		}
		scanf("%d%d", &n1, &n2);
		gcd = getGCD(n1, n2);
		n1 = n1 / gcd * n2;
		N -= 2;
		while(N--){
			scanf("%d", &n2);
			gcd = getGCD(n1, n2);
			n1 = n1 / gcd * n2;
		}
		printf("%d\n", n1);
	}
	return 0;
}
