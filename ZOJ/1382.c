#include<stdio.h>

int main(){
	int d, n,p;
	scanf("%d", &d);
	while(d--){
		scanf("%d", &n);
		p = 0;
		while(!(n&1)){
			p++;
			n = n>>1;
		}
		printf("%d %d\n", n, p);
	}
	return 0;
}
