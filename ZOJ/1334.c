#include<stdio.h>
#include<string.h>

int main(){
	char inbuf[20], outbuf[10], digibuf[3];
	int in, out, sum, p, len, hash[255], tmp;
	memset(hash, 0, sizeof(int)*255);
	for(p='0'; p<='9'; p++)
		hash[p] = p-'0';
	for(p='A'; p<='F'; p++)
		hash[p] = p-'A'+10;

	while(scanf("%s", inbuf) != EOF){
		scanf("%d", &in);
		scanf("%d", &out);
		getchar();

		len = strlen(inbuf);
		sum = 0;
		for(p = 0; p<len; p++)
			sum = sum*in + hash[inbuf[p]];
		for(p = 0; sum>0 && p<7; p++){
			tmp = sum % out;
			if(tmp < 10)
				outbuf[p] = tmp + '0';
			else
				outbuf[p] = tmp + 'A' - 10;
			sum = sum / out;
		}
		if(sum)
			printf("  ERROR\n");
		else{
			p--;
			tmp = 6;
			while(tmp-- > p)
				printf(" ");
			while(p >= 0){
				printf("%c", outbuf[p]);
				p--;
			}
			printf("\n");
		}
	}
	return 0;
}
