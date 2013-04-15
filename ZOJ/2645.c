// Totally don't understand why it is alwasy segmentation falut while submitting...
// WTF

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void strToIp(char buf[], int ip[]){
	char *str, *tok;
	int num, i, p, st;

	str = buf;
	tok = strtok(buf, ".\n");
	num = atoi(tok);
	for(i=0; i<8; i++){
		ip[24+i] = (num & (1<<i)) >>i;
	}

	for(p=1; p<4; p++){
		tok = strtok(NULL, ".\n");
		num = atoi(tok);
		for(i=0; i<8; i++){
			st = 8*(3-p);
			ip[st+i] = (num & (1<<i)) >> i;
		}
	}
}

void updateIp(int ip[], int prefix[], int mask[]){
	int i=31, p;
	while(prefix[i] == ip[i] && mask[i]==1 && i>=0)
		i--;

	if(i >= 0 && mask[i] != 0){
		for(p=i; mask[p]!=0 && p>=0; p--){
			prefix[p] = 0;
			mask[p] = 0;
		}
	}	
}

void printIp(int ip[]){
	int num, i, p;
	for(p=3; p>0; p--){
		num = 0;
		for(i=0; i<8; i++){
			if(ip[8*p+i] != 0)
				num += 1<<i;
		}
		printf("%d.", num);
	}
	num = 0;
	for(i=0; i<8; i++){
		if(ip[i] != 0)
			num += 1<<i;
	}	
	printf("%d\n", num);
}

int main(){
	char buf[20];
	int N, i, ip[32], mask[32], prefix[32];
	while(scanf("%d", &N) && N){
		getchar();
		for(i=0; i<32; i++){
			ip[i] = 0;
			mask[i] = 1;
			prefix[i] = 0;
		}

		fgets(buf, sizeof(buf), stdin);		
		strToIp(buf, prefix);

		for(i=1; i<N; i++){
			fgets(buf, sizeof(buf), stdin);
			strToIp(buf, ip);
			updateIp(ip, prefix, mask);
		}
		printIp(prefix);
		printIp(mask);
	}
	return 0;
}
