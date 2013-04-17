#include<stdio.h>
#include<string.h>

int main(){
	char buf[1000][25], *str, *tok;
	int N, i, modified[1000], allmodified;
	while(scanf("%d", &N) && N){
		getchar();
		allmodified = 0;
		for(i=0; i<N; i++){
			fgets(buf[i], sizeof(buf[i]), stdin);
			modified[i] = 0;
			str = buf[i];
			tok = strtok(str, " ");
			tok = strtok(NULL, " ");
			*(tok-1) = ' ';
			while((*tok) != '\n'){
				if((*tok) == '1'){
					*tok = '@';
					modified[i] = 1;
				}
				if((*tok) == '0'){
					*tok = '%';
					modified[i] = 1;
				}
				if((*tok) == 'l'){
					*tok = 'L';
					modified[i] = 1;
				}
				if((*tok) == 'O'){
					*tok = 'o';
					modified[i] = 1;
				}
				tok++;
			}
			if(modified[i]){
				allmodified++;
			}
		}
		if(!allmodified)
			printf("No account is modified.\n");
		else{
			printf("%d\n", allmodified);
			for(i=0; i<N; i++){
				if(modified[i])
					printf("%s", buf[i]);
			}
		}
	}
	return 0;
}
