#include<stdio.h>
#include<math.h>

int main(){
	int table[21], i, n=0, k;
	double sum = 0, num, tmp, base = log10(2), upper = 4*base;
	
	for(num=2.0; n<21; num++){
		tmp = log10(num);
		sum += tmp;
		if(sum > upper){
			upper *= 2;
			table[n++] = (int)(num+0.001)-1;		
		}
	}

	while(scanf("%d", &k) && k){
		i = (k-1960)/10;
		printf("%d\n", table[i]);
	}

	return 0;
}
