#include<stdio.h>

int main(){
	int N, i, j, ans;
	scanf("%d", &N);
	while(N--){
		scanf("%d%d", &i, &j);
		ans = -1;
		if(i==j && !(i&1))
			ans = 2*i;
		else if(i==j && (i&1))
			ans = 2*i-1;
		else if(j==i-2 && !(i&1))
			ans = i+j;
		else if(j==i-2 && (i&1))
			ans = i+j-1;

		if(ans >= 0)
			printf("%d\n", ans);
		else
			printf("No Number\n");
	}
	return 0;
}
