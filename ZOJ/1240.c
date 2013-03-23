#include<stdio.h>

int main(){
	char buf[60], bufout[60], tmp;
	int N;
	scanf("%d\n", &N);
	int i=1, p;
	while(i<=N){
		fgets(buf, sizeof(buf), stdin);

		p = 0;
		while((tmp = buf[p]) != '\n'){
			if(tmp == 'Z') 
				bufout[p++] = 'A';
			else
				bufout[p++] = tmp+1;
		}
		bufout[p++] = '\n';
		bufout[p] = '\0';
		printf("String #%d\n", i);
		printf("%s\n", bufout);

		i++;
	}

	return 0;
}
