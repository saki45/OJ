#include<stdio.h>

int main(){
	int N, tn;
 	while(scanf("%d", &N)!=EOF){
		tn = (15*N/7)+1;
		if(tn%3 && tn%5)
			tn--;
		printf("%d\n", tn);
	}
	return 0;
}
