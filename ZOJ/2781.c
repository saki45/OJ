#include<stdio.h>

int getRounded(int n){
	int res, base, digit;
	base = 1;
	while(n>=10){
		digit = n%10;
		n /= 10;
		if(digit >=5)
			n++;
		base *= 10;
	}
	res = n * base;
	return res;
}

int main(){
	int T, N, res;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		res = getRounded(N);
		printf("%d\n", res);
	}
	return 0;
}
