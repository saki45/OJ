#include<stdio.h>

int findSum(int N, int facTable[], int n){
	if(N == 0)
		return 1;
	if(n < 0)
		return 0;

	int res = 0;
	if(N >= facTable[n]){
		res = findSum(N-facTable[n], facTable, n-1);
		if(!res){
			res = findSum(N, facTable, n-1);
		}
	}
	else{
		res = findSum(N, facTable, n-1);
	}
	return res;
}

int main(){
	int facTable[10], N, i, res;
	facTable[0] = 1;
	facTable[1] = 1;
	for(i=2; i<10; i++)
		facTable[i] = facTable[i-1]*i;

	while(scanf("%d", &N)!=EOF && N>=0){
		if(N == 0){
			printf("NO\n");
			continue;
		}
		res = findSum(N, facTable, 9);
		if(res)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
