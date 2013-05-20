#include<stdio.h>
#include<string.h>

int main(){
	int i, count[4], n, l;
	char buf[1004];
	while(fgets(buf, sizeof(buf), stdin) != NULL){
		memset(count, 0, sizeof(count));
		l = strlen(buf);
		for(i=0; i<l; i++){
			switch(buf[i]){
				case 'Z':
					count[0]++;
					break;
				case 'O':
					count[1]++;
					break;
				case 'J':
					count[2]++;
					break;
				case '7':
					count[3]++;
					break;
			}
		}

		while(count[0]--)
			printf("Z");
		while(count[1]--)
			printf("O");
		while(count[2]--)
			printf("J");
		while(count[3]--)
			printf("7");

		for(i=0; i<l; i++)
			if(buf[i]!='Z' && buf[i]!='O' && buf[i]!='J' && buf[i]!='7')
				printf("%c", buf[i]);
	}

	return 0;
}
