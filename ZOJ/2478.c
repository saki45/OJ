#include<stdio.h>

int main(){
	char buf[110], cur;
	int N, p, k;
	scanf("%d\n", &N);
	while(N>0){
		fgets(buf, sizeof(buf), stdin);
		p = 0;
		k = 0;
		cur = 0;
		while(buf[p] != '\n'){
			if(buf[p] != cur){
				if(p > 0){
					if(k > 1)
						printf("%d%c", k, cur);
					else
						printf("%c", cur);
				}
				cur = buf[p];
				k = 1;
			}
			else
				k++;

			p++;
		}
		if(k>1)
			printf("%d%c\n", k, cur);
		else
			printf("%c\n", cur);
		N--;
	}

	return 0;
}
