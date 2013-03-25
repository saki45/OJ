#include<stdio.h>
#include<string.h>

int main(){
	char buf[10003], *str;
	str = buf;
	int l, nl, count, p, q;
	while(scanf("%s", str) != EOF){
		l = strlen(str);
		count = 0;

		p = 2*l-2;
		str[p+1] = '\0';
		while(p>0){
			str[p] = str[p/2];
			str[p-1] = '*';
			p -= 2;
		}

		p=0;
		nl = 2*l-2;
		while(p<=nl){
			if(str[p] == '*'){
				q = 1;
				while(p-q>=0 && p+q<=nl){
					if(str[p-q] != str[p+q])
						break;
					q += 2;
					count += 1;
				}
			}
			else{
				count += 1;
				q = 2;
				while(p-q>=0 && p+q<=nl){
					if(str[p-q] != str[p+q])
						break;
					q += 2;
					count += 1;
				}
			}
			p++;
		}
		printf("%d\n", count);
	}
	return 0;
}
