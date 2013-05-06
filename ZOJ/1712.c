#include<string.h>
#include<stdio.h>

int main(){
	int i, sum, l;
	char buf[100];

	while(1){
		scanf("%s", buf);
		l = strlen(buf);
		sum = 0;
		for(i=l-1; i>=0; i--){
			if(buf[i] != '0')
				sum += (buf[i]-'0') * ((1<<(l-i))-1);
		}
		if(sum)
			printf("%d\n", sum);
		else
			break;
	}

	return 0;
}
