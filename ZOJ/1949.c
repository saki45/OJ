#include<stdio.h>

int main(){

	int N, i, j, row[100], col[100], r1, c1, d;
	scanf("%d", &N);
	while(N != 0){
		for(i=0; i<N; i++){
			row[i] = 0;
			col[i] = 0;
		}
		r1 = 0;
		c1 = 0;

		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				scanf("%d", &d);
				if(d == 1){
					if(row[i] == 0)
						r1++;
					else
						r1--;
					row[i] ^= d;

					if(col[j] == 0)
						c1++;
					else
						c1--;
					col[j] ^= d;
				}
			}
		}
		if(r1 == 0 && c1 == 0)
			printf("OK\n");
		else if(r1== 1 && c1 == 1){
			r1 = 0;
			c1 = 0;
			for(i=0; i<N; i++)
				if(row[i] != 0){
					r1 = i+1;
					break;
				}

			for(i=0; i<N; i++)
				if(col[i] != 0){
					c1 = i+1;
					break;
				}
			printf("Change bit (%d,%d)\n", r1, c1);
		}
		else
			printf("Corrupt\n");

		scanf("%d", &N);
	}
	return 0;
}
