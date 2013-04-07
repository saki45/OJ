#include<stdio.h>

int main(){
	int gcd, lcm, i, sum, sqt, x, tmp;
	long long result;
	while(scanf("%d%d", &gcd, &lcm) != EOF){
		if(lcm == gcd){
			printf("1\n");
			continue;
		}
		if(lcm % gcd != 0){
			printf("0\n");
			continue;
		}
		x = lcm / gcd;
		tmp = x/2+1;
		sum = 0;
		for(i=2; i<=tmp; i++){
			if(x % i == 0){
				sum++;
				while(x%i==0)	
					x /= i;
			}
			if(!x)
				break;
		}
		if(x != 1)
			sum++;
		result = 1<<sum;
		printf("%Ld\n", result);
	}
	return 0;
}
