//WA

#include<stdio.h>
#include<string.h>

int main(){
	char buf[1000], ch, cur;
	int i, isRecur, j, k, l, st;

	while(scanf("%s", buf) != EOF){
		l = strlen(buf);
		st = 0;

		while(st<l){
			if(l-st == 1){
				if(buf[st] == '1')
					printf("1111");
				else
					printf("1%c1", buf[st]);
				break;
			}

			i = st+1;
			if(buf[i] == buf[i-1]){
				k = i;
				while(buf[k]==buf[k-1] && k-i<=7)
					k++;
				j = k-i+1;
				printf("%d%c", j, buf[i]);
				st = k;
			}
			else{
				k = i;
				while(buf[k]!=buf[k-1] && k<l)
					k++;
				printf("1");
				if(k==l){
					for(j=st; j<k; j++){
						if(buf[j] == '1')
							printf("1");
						printf("%c", buf[j]);
					}
					printf("1");
					break;
				}
				else{
					for(j=st; j<k-1; j++){
						printf("%c", buf[j]);
						if(buf[j]=='1')
							printf("1");
					}
				}
				printf("1");
				st = k-1;
			}
		}
		printf("\n");
	}
	return 0;
}
