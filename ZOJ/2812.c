#include<stdio.h>

int main(){
	char buf[300];
	int p, curSum;
	while(1){
		curSum = 0;
		p = 0;
		fgets(buf, sizeof(buf), stdin);

		if(buf[0] == '#')
			break;
		while(buf[p] != '\n'){
			if(buf[p] != ' ')
				curSum += (p+1)*(int)(buf[p]-'A'+1);
			p++;
		}
		printf("%d\n", curSum);
	}

	return 0;
}
