#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int N, a[50000], ans[50000], i, l, k, x, X, Y, pAns, len;
	char buf[50000], ch;
	scanf("%d", &N);
	while(N--){
		scanf("%s", buf);
		X = atoi(buf);
		scanf("%s", buf);
		Y = atoi(buf);

		scanf("%s", buf);
		len = strlen(buf);
		for(i=0; i<len; i++){
			if(buf[i]>='0' && buf[i]<='9')
				a[i] = buf[i] - '0';
			else if(buf[i] >='A' && buf[i]<='Z')
				a[i] = buf[i] - 'A' + 10;
			else
				a[i] = buf[i] - 'a' + 36;
		}

		pAns = 0;
		l = 0;
		while(l < len){
			x = 0;
			for(i=l; i<len; i++){
				k = (x*X+a[i]) / Y;
				x = (x*X+a[i]) % Y;
				a[i] = k;
			}
			ans[pAns++] = x;

			while(a[l] == 0 && l < len)
				l++;
		}

		printf("%d %s\n", X, buf);
		printf("%d ", Y);
		for(i = pAns-1; i>=0; i--){
			if(ans[i] >= 0 && ans[i] <= 9)
				ch = ans[i]+'0';
			else if(ans[i] >= 10 && ans[i] <= 35)
				ch = ans[i]-10+'A';
			else
				ch = ans[i]-36+'a';
			printf("%c", ch);
		}
		printf("\n\n");
	}
	return 0;
}
