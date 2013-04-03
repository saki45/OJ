#include<stdio.h>

int main(){
	int N1, N2, N3;
	scanf("%d%d%d", &N1, &N2, &N3);
	if(N1 <= 168)
		printf("CRASH %d\n", N1);
	else if(N2 <= 168)
		printf("CRASH %d\n", N2);
	else if(N3 <= 168)	
		printf("CRASH %d\n", N3);
	else
		printf("NO CRASH\n");

	return 0;
}
