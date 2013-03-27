// This code is not correct although I could not find out why :<

#include<stdio.h>
#include<string.h>

struct key{
	char str[22];
	int length;
};

struct excuse{
	char str[75];
	int m;
};

void toLowerCase(char *s){
	while(*s != '\n'){
		if(*s >= 'A' && *s <= 'Z')
			*s = *s - 'A' + 'a';	
		s++;
	}
}

int match(char *str1, int st, int ed, char *str2){
	int i=st;
	str1 = &str1[st];
	while(i<ed){
		if(*str1 == *str2){
			str1 ++;
			str2 ++;
			i++;
		}
		else
			return 0;
	}
	return 1;
}

int matchAll(char *ex, struct key keys[], int K){
	int st, ed, allMatch=0, len, i;
	st = 0;
	while(ex[st] != '\n' && ex[st] != '\0'){
		if(ex[st] >= 'a' && ex[st] <= 'z'){
			ed = st;
			while(ex[ed] >= 'a' && ex[ed] <= 'z')
				ed++;
			len = ed - st;
			for(i=0; i<K; i++){
				if(keys[i].length == len){
					allMatch += match(ex, st, ed, keys[i].str);
				}
			}
			st = ed+1;
		}
		else{
			st++;
		}
	}
	return allMatch;
}

int main(){
	int K, E, i, maxMatch, thisMatch, nSet;
	struct key keys[20];
	struct excuse ex[20];
	nSet = 1;

	while(scanf("%d%d", &K, &E) != EOF){
		getchar();
		for(i=0; i<K; i++){
			scanf("%s", keys[i].str);
			keys[i].length = strlen(keys[i].str);
		}
		maxMatch = 0;
		getchar();

		for(i=0; i<E; i++){
			fgets(ex[i].str, 75, stdin);
			toLowerCase(ex[i].str);
			thisMatch = matchAll(ex[i].str, keys, K);
			ex[i].m = thisMatch;
			if(thisMatch > maxMatch)
				maxMatch = thisMatch;
		}

		printf("Excuse Set #%d\n", nSet);
		nSet++;
		for(i=0; i<E; i++){
			if(ex[i].m == maxMatch)
				printf("%s", ex[i].str);
		}
		printf("\n");
	}
	return 0;
}
