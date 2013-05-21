#include<stdio.h>
#include<string.h>

int main(){
	int T, x, y, n, i, m, tmp;
	int hash[1000];
	memset(hash, 0, sizeof(hash));
	for(m=1; m<=12; m++)
		hash[m*m] = 1;

	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &x, &y);

		n = 0;
		for(i=x; i<=y; i++){
			if(hash[i%100] || hash[i%1000])
				n++;
		}
		printf("%d\n", n);
	}
	return 0;
}
