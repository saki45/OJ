#include<stdio.h>
#include<math.h>

int main(){
	int N, n, prevSum, prevTotal, total;
	double log3 = log(3);
	scanf("%d", &N);
	while(N>0){
		if(N == 1)
			printf("0\n");
		else if(N <= 3)
			printf("1\n");
		else{
			n = (int)(log(N-0.1)/log3)+1;
			prevSum = pow(3, n-1);
			prevTotal = (prevSum-1)>>1;
			total = prevTotal + ceil((N-prevSum)/2.0);
			printf("%d\n", total);
		}
		scanf("%d", &N);
	}
	return 0;
}
