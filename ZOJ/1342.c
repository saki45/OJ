#include<stdio.h>
#include<string.h>

int main(){
	int i, j, k, a[26][5], s[26][5], isValid, len, p, sum, ch, prevCh;
	char buf[8];

	memset(a, 0, sizeof(int)*26*5);
	memset(s, 0, sizeof(int)*26*5);

	for(i=0; i<26; i++){
		a[i][0] = 1;
		s[i][0] = i;
	}
	
	for(k=1; k<5; k++){
		s[0][k] = s[26-k][k-1] + a[26-k][k-1];
		for(i=0; i<26-k; i++){
			a[i][k] = s[0][k] - s[i+1][k-1];
		}
		for(i=1; i<26-k; i++){
			s[i][k] = s[i-1][k] + a[i-1][k];
		}
	}

	while(scanf("%s", buf) != EOF){
		isValid = 1;
		len = strlen(buf);
		if(len > 1){
			for(p=1; p<len; p++)
				if(buf[p] <= buf[p-1]){
					isValid = 0;
					break;
				}
			if(!isValid){
				printf("0\n");
				continue;
			}
		}
		sum = 0;
		if(len == 1){
			sum = buf[0]-'a'+1;
		}
		else{
			k = 1;
			ch = buf[0] - 'a';
			sum += s[ch][len-1];
			while(k < len){
				ch = buf[k] - 'a';
				prevCh = buf[k-1] - 'a';
				sum += s[ch][len-1-k] - s[prevCh+1][len-1-k];
				k++;
			}
			sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}
