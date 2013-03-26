#include<stdio.h>

int main(){
	int t, n, sum, tmp;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		sum = 1-n;
		while(n--){
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum);
	}
	return 0;
}
