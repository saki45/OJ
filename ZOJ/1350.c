#include<stdio.h>

int main(){
	int N ,n, num[10]= {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}, i;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &n);
		i=0;
		while(num[i] <= n && i<10)
			i++;
		printf("%d\n", i);

	}
	return 0;
}
