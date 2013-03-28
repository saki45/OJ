#include<stdio.h>

int main(){
	int N, n, i, nOdd, nEven, tmp;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &n);
		nOdd = 0;
		nEven = 0;
		for(i=0; i<n; i++){
			scanf("%d", &tmp);
			if(tmp == 1){
				if(i%2 == 0)
					nEven++;
				else
					nOdd++;
			}
		}

		if(n%2 == 1)
			printf("YES\n");
		else{
			if(nEven == nOdd || nEven-nOdd == 1 || nOdd - nEven == 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
