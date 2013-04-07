#include<stdio.h>

int main(){
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");

	double sum=1, fact=1;;
	int i;
	for(i=1; i<=9; i++){
		fact *= i;
		sum += 1/fact;
		if (i == 1)
			printf("1 2\n");
		else if(i == 2)
			printf("%d %.1lf\n", i, sum);
		else
			printf("%d %.9lf\n", i, sum);
			
	}

	return 0;
}
