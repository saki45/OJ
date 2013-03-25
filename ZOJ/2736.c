#include<stdio.h>

int isDaffodil(char buf[], int cubic[]){

	int sum = 0, sumCubic = 0, p = 0, digit;
	while(p<3){
		digit = (int)(buf[p++] - '0');
		sum = sum*10 + digit;
		sumCubic += cubic[digit];
	}

	return !(sum-sumCubic);
}

int main(){
	char buf[10];
	int cubic[10];

	int i;
	for(i=0; i<10; i++)
		cubic[i] = i*i*i;

	while(scanf("%s", buf) != EOF){
		if(isDaffodil(buf, cubic))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
