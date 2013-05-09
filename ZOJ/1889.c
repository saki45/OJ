#include<stdio.h>

int main(){
	int N, count, r;
	while(scanf("%d", &N) != EOF){
		count = 1;
		r = 1;
		while(r % N != 0){
			r = (r*10+1) % N;
			count ++;
		}
		printf("%d\n", count);
	}
	return 0;
}
