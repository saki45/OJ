#include<stdio.h>

#define PI 3.14169265359
#define eps 0.00000001

int main(){
	double a, b;
	int N, nYear, count;
	count = 1;
	scanf("%d", &N);
	while(N--){
		scanf("%lf %lf", &a, &b);
		nYear = (int)((a*a+b*b)*PI)/100.0 + 1;
		printf("Property %d: This property will begin eroding in year %d.\n", count, nYear);
		count++;
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
