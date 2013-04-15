#include<stdio.h>
#include<string.h>

int main(){
	int M, N, L, Ci[2000], sum[100000], prev[100000], i, s, nM, tmp;
	while(scanf("%d%d", &M, &L) && (M+L)){
		scanf("%d", &N);
		int curSum = 0;
		for(i=0; i<N; i++){
			scanf("%d", &Ci[i]);
			curSum += Ci[i];
		}

		if(curSum > M+L){
			printf("Impossible to distribute\n");
			continue;
		}

		memset(sum, 0, sizeof(sum));
		memset(prev, 0, sizeof(prev));

		sum[0] = 1;
		curSum = 0;
		for(i=N-1; i>=0; i--){
			curSum += Ci[i];
			tmp = Ci[i];
			for(s = curSum; s>=tmp; s--){
				if(sum[s-tmp] > 0 && sum[s] == 0){
					sum[s] = sum[s-tmp] + 1;
					prev[s] = i;
				}
			}
		}

		s = M;
		while(s>0 && sum[s] == 0)
			s--;

		if(curSum - s > L)
			printf("Impossible to distribute\n");
		else{
			nM = sum[s] - 1;
			printf("%d", nM);
			while(s > 0){
				printf(" %d", prev[s]+1);
				s = s - Ci[prev[s]];
			}
			printf("\n");
		}
	}
	return 0;
}
