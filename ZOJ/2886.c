#include<stdio.h>

int main(){
	char buf[1010], cur;
	int N, p, k;

	scanf("%d\n", &N);
	while(N>0){
		p = 0;
		k = 0;
		cur = 0;
		fgets(buf, sizeof(buf), stdin);

		while(buf[p] != '\n'){
			if(buf[p] != cur){
				if(p>0)
					printf("%d%c", k, cur);
				cur = buf[p];
				k = 1;
			}
			else
				k++;
			p++;
		}
		printf("%d%c\n", k, cur);
		N--;
	}

	return 0;
}
