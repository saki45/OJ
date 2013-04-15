#include<stdio.h>

int main(){
	int N, tmp, sum10, sum12, sum16;
	for(N = 2992; N<10000; N++){
		tmp = N;
		sum10 = 0;
		sum12 = 0;
		sum16 = 0;
		while(tmp > 0){
			sum10 += tmp%10;
			tmp /= 10;
		}
		tmp = N;
		while(tmp > 0){
			sum12 += tmp%12;
			tmp /= 12;
		}
		if(sum10 != sum12)
			continue;

		tmp = N;
		while(tmp > 0){
			sum16 += tmp%16;
			tmp /= 16;
		}

		if(sum10 == sum16)
			printf("%d\n", N);

	}
	return 0;
}
