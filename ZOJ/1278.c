#include<stdio.h>
#include<string.h>

int main(){
	int hit[10000], L, I, Z, M, caseCount, length, st;
	caseCount = 1;
	while(scanf("%d%d%d%d", &Z, &I, &M, &L) && (L+I+Z+M)){
		memset(hit, 0, sizeof(hit));
		length = 0;
		while(!hit[L]){
			hit[L] = 1;
			L = (Z*L+I)%M;
		}
		st = L;
		do{
			L = (Z*L+I)%M;
			length++;
		}while(L != st);
		printf("Case %d: %d\n", caseCount, length);
		caseCount++;
	}
	return 0;
}
