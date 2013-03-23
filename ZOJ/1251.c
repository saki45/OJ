#include<stdio.h>

int main(){
	int N, avg, cum, arr[51], p, tmp, setCount;

	setCount = 1;
	scanf("%d", &N);
	while(N > 0){
		cum = 0;
		for(p=0; p<N; p++){
			scanf("%d", &tmp);
			cum += tmp;
			arr[p] = tmp;
		}
		avg = cum / N;
		cum = 0;
		for(p=0; p<N; p++){
			if(arr[p] > avg)
				cum += arr[p] - avg;
		}
		printf("Set #%d\n", setCount++);
		printf("The minimum number of moves is %d.\n\n", cum);
		scanf("%d", &N);
	}	
	return 0;
}
