#include<stdio.h>

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		if(N%4 == 2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
