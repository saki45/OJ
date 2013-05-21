#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int sa[30], sb[30], sc[30], la, lb, lc, ia, ib, ic, primeList[40], isPrime[150], i, j, pc, carry;
	char bufa[100], bufb[100], *tok, *str;
	memset(isPrime, 1, sizeof(isPrime));
	pc = 0;
	for(i=2; i<150; i++){
		if(isPrime[i]){
			primeList[pc++] = i;
			for(j=2*i; j<150; j+=i)
				isPrime[j] = 0;		
		}
	}

	while(scanf("%s%s", bufa, bufb)!=EOF){
		la = 0;
		lb = 0;

		str = bufa;
		tok = strtok(str, ", \n");
		while(tok != NULL){
			sa[la++] = atoi(tok);
			tok = strtok(NULL, ", \n");
		}

		str = bufb;
		tok = strtok(str, ", \n");
		while(tok != NULL){
			sb[lb++] = atoi(tok);
			tok = strtok(NULL, ", \n");
		}

		carry = 0;
		ia = la-1;
		ib = lb-1;
		ic = 0;

		while(ia>=0 && ib>=0){
			sc[ic] = (sa[ia]+sb[ib]+carry) % primeList[ic];
			carry = (sa[ia]+sb[ib]+carry) / primeList[ic];
			ia--;
			ib--;
			ic++;
		}

		while(ia>=0){
			sc[ic] = (sa[ia]+carry) % primeList[ic];
			carry = (sa[ia]+carry) / primeList[ic];
			ia--;
			ic++;
		}
		while(ib>=0){
			sc[ic] = (sb[ib]+carry) % primeList[ic];
			carry = (sb[ib]+carry) / primeList[ic];
			ib--;
			ic++;
		}

		if(carry!=0)
			sc[ic++] = carry;

		lc = ic;
		for(ic=lc-1; ic>0; ic--)
			printf("%d,", sc[ic]);
		printf("%d\n", sc[0]);
	}
	return 0;
}
