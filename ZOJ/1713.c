#include<stdio.h>
#include<string.h>

int getVowel(char *p){
	char *q;
	int nV = 0;
	while(*p){
		if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || *p == 'y'){
			q = p+1;
			if(!(*q == 'a' || *q == 'e' || *q == 'i' || *q == 'o' || *q == 'u' || *q == 'y')){
				nV++;
			}
		}
		p++;
	}
	return nV;
}

int main(){
	int nV, len;
	char buf[10000], *str, *tok; 
	fgets(buf, sizeof(buf), stdin);
	while(strcmp(buf, "e/o/i\n")){
		str = buf;
		tok = strtok(str, "/\n");
		nV = getVowel(tok);
		if(nV == 5){
			tok = strtok(NULL, "/\n");
			nV = getVowel(tok);
			if(nV == 7){
				tok = strtok(NULL, "/\n");
				nV = getVowel(tok);
				if(nV == 5)
					printf("Y\n");
				else
					printf("3\n");
			}
			else
				printf("2\n");
		}
		else
			printf("1\n");

		fgets(buf, sizeof(buf), stdin);
	}
	return 0;
}
