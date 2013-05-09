#include<stdio.h>

int main(){
	int i, nCase, T, M;
	char buf[100];

	scanf("%d", &T);
	nCase = 1;
	while(T--){
		scanf("%d %s", &M, buf);
		printf("%d ", nCase++);

		i = 0;
		while(buf[i] != '\0'){
			if(M != i+1)
				printf("%c", buf[i]);
			i++;
		}
		printf("\n");
	}
	return 0;
}
