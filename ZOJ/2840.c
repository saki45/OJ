#include<stdio.h>
#include<string.h>

int match(char *str, char *pattern){
	if(*str == '\0' && *pattern == '\0')
		return 1;
	if(*str == '\0')
		if(*pattern == '*')
			return match(str, pattern+1);
		else
			return 0;

	if(*pattern != '*'){
		if(*str == *pattern)
			return match(str+1, pattern+1);
		else
			return 0;
	}
	else{
		int res1 = match(str+1, pattern);
		int res2 = match(str+1, pattern+1);
		int res3 = match(str, pattern+1);
		return res1 || res2 || res3;
	}
}

int main(){
	int N, M, i, j, hasMatch, isEOF, isFirst;
	char file[100][67], buf[67], *query;
	isFirst = 1;
	isEOF = scanf("%d", &N);
	while(isEOF != EOF){
		if(isFirst){
			isFirst = 0;
		}
		else{
			printf("\n");
		}
		getchar();
		for(i=0; i<N; i++){
			scanf("%s", file[i]);
		}
		scanf("%d", &M);
		getchar();
		for(i=0; i<M; i++){
			scanf("%s", buf);
			query = buf;
			hasMatch = 0;
			for(j=0; j<N; j++){
				if(match(file[j], query)){
					if(hasMatch)
						printf(", ");
					hasMatch = 1;
					printf("%s", file[j]);
				}
			}
		
			if(!hasMatch)
				printf("FILE NOT FOUND");
			printf("\n");
		}
		isEOF = scanf("%d", &N);
	}
	return 0;
}
