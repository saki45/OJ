#include<stdio.h>

int getFirstSum(char *buf){
	int result = 0;
	while(*buf != '\n'){
		result += (int)(*buf - '0');
		buf++;
	}
	return result;
}

int main(){
	int num, root;
	char buf[50000];
	fgets(buf, sizeof(buf), stdin);
	while(buf[0] != '0'){
		num = getFirstSum(buf);
		do{
			root = 0;
			while(num > 0){
				root += num % 10;
				num /= 10;
			}
			num = root;
		}while(num >= 10);
		printf("%d\n", num);
		fgets(buf, sizeof(buf), stdin);
	}
	return 0;
}
