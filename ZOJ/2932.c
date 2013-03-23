#include<stdio.h>

int main(){
	char buf[85];
	int p;
	while(1){
		fgets(buf, sizeof(buf), stdin);
		p = 0;
		if(buf[0] == '#')
			break;

		while(buf[p] != '\n'){
			switch(buf[p]){
				case ' ':
					printf("%%20");
					break;
				case '!':
					printf("%%21");
					break;
				case '$':
					printf("%%24");
					break;
				case '%':
					printf("%%25");
					break;
				case '(':
					printf("%%28");
					break;
				case ')':
					printf("%%29");
					break;
				case '*':
					printf("%%2a");
					break;
				default:
					printf("%c", buf[p]);
			}
			p++;
		}
		printf("\n");
	}
	return 0;
}
