#include<stdio.h>
#include<string.h>

int main(){
	char buf[205];
	int i;
	fgets(buf, sizeof(buf), stdin);
	while(strcmp(buf, "ENDOFINPUT\n")){
		fgets(buf, sizeof(buf), stdin);
		for(i = 0; buf[i]!='\n'; i++){
			if(buf[i] >='A' && buf[i] <= 'Z')
				buf[i] = (buf[i]-'A'+21)%26 + 'A';
		}
		printf("%s", buf);
		fgets(buf, sizeof(buf), stdin);
		fgets(buf, sizeof(buf), stdin);
	}
	return 0;
}
