#include<stdio.h>
#include<string.h>

int main(){
	int hash[100], N, count;
	scanf("%d", &N);

	while(N != -1){
		memset(hash, 0, 100*sizeof(int));
		count = 0;
		while(N != 0){
			hash[N] ++;
			if(N%2 == 0)
				count += hash[N/2];
			if(N<50)
				count += hash[N*2];
			scanf("%d", &N);
		}
		printf("%d\n", count);
		scanf("%d", &N);
	}
	return 0;
}
