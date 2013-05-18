#include<stdio.h>

int main(){
	int i, j, N, l, line, nl;
	char buf[1000], out[1000], ch;
	while(scanf("%d", &N)!=EOF){
		l = 0;
		for(i=0; i<N; i++){
			scanf("%s", buf);
			for(j=0; buf[j]!='\0'; j++){
				out[l++] = buf[j];
			}
		}

		line = l/N;
		nl = 0;
		for(i=l-1; i>l-1-line; i--){
			for(j=0; j<N; j++){
				ch = out[i-j*line];
				if(ch == '_')
					ch = ' ';
				else if(ch == '\\')
					ch = '\n';
				buf[nl++] = ch;
			}
		}

		nl--;
		while(buf[nl]==' ')
			nl--;
		buf[nl+1] = '\0';

		printf("%s\n\n", buf);
	}
	return 0;
}
