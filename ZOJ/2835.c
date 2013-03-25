#include<stdio.h>

void clear(int hash[], int rSum[], int cSum[], int *d1Sum, int *d2Sum){
	int i;
	for(i=0; i<1001; i++)
		hash[i] = 0;
	for(i=0; i<10; i++){
		rSum[i] = 0;
		cSum[i] = 0;
	}
	*d1Sum = 0;
	*d2Sum = 0;
}

int main(){
	int N;
	int hash[1001], rSum[10], cSum[10], d1Sum, d2Sum, i, j, hasDup, tmp;

	scanf("%d", &N);
	while(N != 0){
		hasDup = 0;
		clear(hash, rSum, cSum, &d1Sum, &d2Sum);

		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				scanf("%d", &tmp);
				if(!hasDup){
					if(!hash[tmp]){
						hash[tmp] = 1;
						rSum[i] += tmp;
						cSum[j] += tmp;
						if(i == j)
							d1Sum += tmp;
						if(i+j == N-1)
							d2Sum += tmp;
					}
					else{
						hasDup = 1;
					}
				}
			}
		}
		if(hasDup)
			printf("No\n");
		else{
			if(d2Sum != d1Sum)
				printf("No\n");
			else{
				hasDup = 1;
				for(i=0; i<N; i++){
					if(rSum[i] != d1Sum){
						hasDup = 0;
						break;
					}
				}
				if(hasDup){
					for(j=0; j<N; j++){
						if(cSum[j] != d1Sum){
							hasDup = 0;
							break;
						}
					}
				}
				if(hasDup)
					printf("Yes\n");
				else
					printf("No\n");
			}
		}

		scanf("%d", &N);
	}

	return 0;
}
