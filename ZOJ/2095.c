#include<stdio.h>

int main(){
	int table[500001], i, j, N, t;
	table[0] = 0;
	table[1] = 0;
	for(i=2; i<=500000; i++)
		table[i] = 1;
	for(i=2; i<250001; i++){
		for(j=2*i; j<500001; j+=i)
			table[j] += i;
	}

	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		printf("%d\n", table[N]);
	}
	return 0;
}
