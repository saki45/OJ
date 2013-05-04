#include<stdio.h>
#include<string.h>

int isCocaCola(int n){
	if(n%7 == 0)
		return 1;

	while(n>0){
		if(n%10 == 7)
			return 1;
		n /= 10;
	}
	return 0;
}

int main(){
	int p[100], n, digit, count, start, T;
	memset(p, 0, sizeof(p));

	count = 0;
	start = 0;

	for(n=1; n<800; n++){
		if(isCocaCola(n)){
			if(count == 0){
				count = 1;
				start = n;
			}
			else{
				count ++;
			}
			if(p[count] == 0)
				p[count] = start;
		}
		else{
			count = 0;
		}
	}	

	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		printf("%d\n", p[n]);
	}
	return 0;
}
