#include<stdio.h>
#include<string.h>

int main(){
	int T, nCase;
	double in, out;
	char buf[5];
	scanf("%d", &T);

	nCase = 1;
	while(T--){
		scanf("%lf %s", &in, buf);
		if(strcmp(buf, "kg") == 0){
			out = in * 2.2046;
			printf("%d %.4lf lb\n", nCase, out);
		}
		if(strcmp(buf, "lb") == 0){
			out = in * 0.4536;
			printf("%d %.4lf kg\n", nCase, out);
		}
		if(strcmp(buf, "l") == 0){
			out = in * 0.2642;
			printf("%d %.4lf g\n", nCase, out);
		}
		if(strcmp(buf, "g") == 0){
			out = in * 3.7854;
			printf("%d %.4lf l\n", nCase, out);
		}
		nCase++;		
	}

	return 0;
}
