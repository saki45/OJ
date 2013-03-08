#include<stdio.h>
#include<stdlib.h>

int main(){
	int N, K;
	scanf("%d %d", &N, &K);

	long long *profit = (long long*)calloc(N, sizeof(long long));

	// read in the profit for each billboard
	int n;
	for(n=0; n<N; n++)
		scanf("%Ld", &profit[n]);

	long long *cumSum = (long long*)malloc(N*sizeof(long long));
	cumSum[0] = profit[0];
	for(n=1; n<N; n++)
		cumSum[n] = cumSum[n-1] + profit[n];

	if(N == K){
		printf("%Ld\n", cumSum[N-1]);
		free(profit);
		free(cumSum);
		return 0;
	}

	long long *prevMax = (long long*)calloc(N, sizeof(long long));
	long long maximum = profit[0], maximum2 = 0, tmpSum = 0, tmpIdx = 0;
	int maxIdx = 1, maxIdx2 = 0;

	for(n=1; n<N; n++){
		prevMax[n] = maximum;

		if(maxIdx < K){
			// update maximum
			maximum += profit[n];
			maxIdx ++;

			// if maxIdx = 1 and maxIdx2 = 0, we just keep the current maximum2
			// else we will update maximum2 
			if(!(maxIdx == 1 && maxIdx2 == 0)){
				maximum2 += profit[n];
				if(maximum2 <= prevMax[n]){
					maximum2 = prevMax[n];
					maxIdx2 = 0;
				}
				else{
					maxIdx2 ++;
				}
			}
		}
		else{
			// find new maximum (whether it is larger than maximum2+profit[n])
			maximum2 += profit[n];

			// update maximum with the previous maximum
			// in this case maximum and maximum2 are of the same value
			if(maximum2 <= maximum){
				maxIdx = 0;
				maxIdx2 = 0;
				maximum2 = maximum;
			}
			else{
			// replace maximum with the maximum2+profit[n]
				maximum = maximum2;
				maxIdx = maxIdx2+1;
				
				// find new maximum2
				// the idx of maximum2 should be within [0, maxIdx2], so we search accordingly
				int p;
				maximum2 = prevMax[n];
				tmpIdx = 0;
				for(p=1; p<=maxIdx2; p++){
					tmpSum = prevMax[n-p] + cumSum[n] - cumSum[n-p];
					if(tmpSum > maximum2){
						maximum2 = tmpSum;
						tmpIdx = p;
					}
				}
				maxIdx2 = tmpIdx;
			}
		}
		//printf("%Ld %Ld %Ld\n", profit[n], maximum, maximum2);
	}
	
	printf("%Ld\n", maximum);
	free(profit);
	free(cumSum);
	free(prevMax);

	return 0;
}
