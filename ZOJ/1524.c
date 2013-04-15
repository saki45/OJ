#include<stdio.h>
#include<string.h>

int main(){
	int M, N, list[105],  prev[105], i, j, p, citem;
	double ans[105], cprice;
	memset(list, 0, sizeof(list));
	while(scanf("%d%d", &M, &N) && (M+N)){
		for(i=1; i<=M; i++)
			scanf("%d", &list[i]);

		memset(prev, 0, sizeof(prev));
		memset(ans, 0, sizeof(ans));

		for(i=M; i>0; i--){
			j = i-1;
			while(j>0 && list[j] != list[i]){
				j--;
			}
			prev[i] = j;
		}

		p = 1;
		for(i=0; i<N; i++){
			scanf("%d %lf", &citem, &cprice);
			for(j=p; j>0;){
				if(citem == list[j]){
					if(ans[j] == 0){
						ans[j] = ans[j-1] + cprice;
						if(p<M)
							p++;
					}
					else{
						if(ans[j] > ans[j-1] + cprice)
							ans[j] = ans[j-1] + cprice;
					}
					j = prev[j];
				}
				else
					j--;
			}
		}

		if(ans[M] == 0)
			printf("Impossible\n");
		else
			printf("%.2lf\n", ans[M]);

	}
	return 0;
}
