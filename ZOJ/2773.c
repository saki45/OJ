#include<stdio.h>

int main(){
	int N, n, i, nCase;
	long long T[3003], W[3003];
	T[0] = 0;
	W[0] = 0;

	for(i=1; i<=3002; i++)
		T[i] = T[i-1]+i;
	for(i=1; i<=3000; i++)
		W[i] = W[i-1]+i*T[i+1];

	scanf("%d", &N);
	nCase = 1;
	while(nCase <= N){
		scanf("%d", &n);
		printf("%d %d %Ld\n", nCase, n, W[n]);
		nCase++;
	}

	return 0;
}
