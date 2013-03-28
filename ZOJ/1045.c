#include<stdio.h>

int main(){
	double n, s;
	int table[530], tn, i=2, p=1;
	table[0] = 0;
	s = 0;
	while(s<5.21){
		s += 1.0/i;
		while(p <= (int)(s*100)){
			table[p++] = i-1;
		}
		i++;
	}

	scanf("%lf", &n);

	while(n > 0){
		tn = (int)((n+0.001)*100.0);
		printf("%d card(s)\n", table[tn]);
		scanf("%lf", &n);
	}

	return 0;
}
