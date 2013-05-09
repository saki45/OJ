#include<stdio.h>
#include<stdlib.h>

int dfs(char ans[], int *l, int n, int r){
	if(r == 0)
		return 1;
	if((*l) >= 100){
		(*l)--;
		return 0;
	}

	int res, tr, rnd;
	rnd = rand() & 1;

	ans[(*l)] = rnd + '0';
	(*l)++;
	tr = (r*10+rnd) % n;
	res = dfs(ans, l, n, tr);

	if(res)
		return 1;

		
	ans[(*l)] = 1 - rnd + '0';
	(*l)++;
	tr = (r*10+1-rnd) % n;
	res = dfs(ans, l, n, tr);

	if(res)
		return 1;
	
	(*l)--;
	return 0;
}

int main(){
	int n, i, l;
	char ans[102];

	while(scanf("%d", &n) && n){
		if(n == 1){
			printf("1\n");
			continue;
		}

		ans[0] = '1';
		l = 1;
		dfs(ans, &l, n, 1);
		ans[l] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}
