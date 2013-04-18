#include<stdio.h>
#include<string.h>

int main(){
	int sum[210000], i, j, pairs[21][2], N, p;
	memset(sum, 0, sizeof(sum));
	for(i=1; i<105001; i++){
		j = 2*i;
		while(j<210000){
			sum[j] += i;
			j += i;
		}
	}

	p = 0;
	for(i=2; i<210000; i++){
		j = sum[i];
		if(j<210000 && sum[j] == i && i<j){
			pairs[p][0] = i;
			pairs[p][1] = j;
			p++;
		}
	}

	while(scanf("%d", &N)!=EOF){
		printf("%d %d\n", pairs[N-1][0], pairs[N-1][1]);
	}
	return 0;
}
