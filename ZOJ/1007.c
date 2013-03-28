#include<stdio.h>

int main(){
	double x, psix, j;
	for(x = 0; x<2.000000001; x+=0.001){
		psix = 0;
		for(j=1; j<10000; j++)
			psix += 1.0/(j*(j+1)*(j+x));
		psix *= 1-x;
		psix += (1-x)/(2*10000*10000) + 1.0;
		printf("%5.3lf %16.12lf\n", x, psix);
	}

	return 0;
}
