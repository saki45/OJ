#include<stdio.h>
#include<string.h>

int main(){
	char str[22], *p;
	int hasVowel, isValid, con_v, con_c;
	scanf("%s", str);
	while(strcmp(str, "end")){
		p = str;
		hasVowel = 0;
		isValid = 1;
		con_v = 0;
		con_c = 0;
		while(*p != '\0'){
			if(*p == *(p+1) && !(*p == 'e' || *p == 'o')){
				isValid = 0;
				break;
			}

			if(*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u'){
				hasVowel = 1;
				con_c = 0;
				con_v++;
				if(con_v == 3){
					isValid = 0;
					break;
				}
			}
			else{
				con_v = 0;
				con_c++;
				if(con_c == 3){
					isValid = 0;
					break;
				}
			}
			p++;
		}

		if(hasVowel == 0)
			isValid = 0;

		if(isValid)
			printf("<%s> is acceptable.\n", str);
		else
			printf("<%s> is not acceptable.\n", str);

		scanf("%s", str);
	}
	return 0;
}
