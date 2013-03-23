#include<stdio.h>

int main(){
	char buf[80], tmp, *p, *q;
	int N;
	scanf("%d\n", &N);
	while(N>0){
		fgets(buf, sizeof(buf), stdin);
		p = buf;
		q = buf;
		while(*q != '\n')
			q++;
		q--;
		while(p < q){
			tmp = *q;
			*q = *p;
			*p = tmp;
			q--;
			p++;
		}
		printf("%s", buf);
		N--;
	}
	return 0;
}
