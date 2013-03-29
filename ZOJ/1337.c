#include<stdio.h>
#include<math.h>

int gcd(int a, int b){
	int tmp;
	if(a<b){
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b != 0){
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

int main(){
	int N, buf[50], p, i, j, count, M;
	double ePi;
	scanf("%d", &N);
	while(N>0){
		for(p=0; p<N; p++)
			scanf("%d", &buf[p]);

		count = 0;
		M = 0;
		for(i=0; i<N-1; i++){
			for(j=i+1; j<N; j++){
				M++;
				if(gcd(buf[i], buf[j]) == 1)
					count++;
			}
		}

		if(count == 0)
			printf("No estimate for this data set.\n");
		else{
			ePi = 6.0*M/count;
			ePi = sqrt(ePi);
			printf("%.6lf\n", ePi);
		}

		scanf("%d", &N);
	}
	return 0;
}
