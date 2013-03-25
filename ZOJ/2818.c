#include<stdio.h>
#include<math.h>

int main(){
	int A, B, N;
	double root, pow1, pow2;

	scanf("%d %d", &B, &N);
	while(B!=0 && N!=0){
		root = pow(B, 1.0/N);
		A = (int)root;
		pow1 = pow(A, N);
		pow2 = pow(A+1, N);
		A = (B-pow1) > (pow2-B)?A+1:A;
		printf("%d\n", A);

		scanf("%d %d", &B, &N);
	}
	return 0;
}
