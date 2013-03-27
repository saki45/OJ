#include<stdio.h>

int main(){
	int t, N, tmp, mid, i, j, found;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		mid = 0;
		for(i=0; i<3; i++){
			scanf("%d", &tmp);
			mid = mid*10 + tmp;
		}
		mid *= 10;
		found = 0;

		for(i=9; i>0; i--){
			for(j=9; j>=0; j--){
				if((10000*i+mid+j) % N == 0){
					found = (10000*i+mid+j) / N;
					break;
				}
			}
			if(found)
				break;
		}
		if(found)
			printf("%d %d %d\n", i, j, found);
		else
			printf("0\n");
	}
	return 0;
}
