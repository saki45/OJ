#include<stdio.h>

int main(){
	int N, sgn, sum, cur, n, curBit, b, nums[7], i, st, ed, mask6;
	mask6 = (1<<6)-1;
	while(scanf("%d", &N) && N>=0){
		sum = 0;
		while(N){
			for(i=0; i<7; i++)
				scanf("%d", &nums[i]);

			n = 0;
			b = 15;
			for(i=0; i<16; i++){
				cur = 0;
				if(nums[n] & (1<<b))
					sgn = -1;
				else
					sgn = 1;
				if(b==0){
					b = 15;
					n++;
				}
				else
					b--;

				if(b>=5){
					cur = (nums[n]>>(b-5)) & mask6;
					b -= 6;
					if(b<0){
						b = 15;
						n++;
					}
				}
				else{
					cur = (nums[n] & ((1<<(b+1))-1))<<(5-b);
					cur |= (nums[n+1]>>(11+b)) & ((1<<(6-b))-1);
					b = 10+b;
					n++;
				}

				cur *= sgn;
				sum += cur;
			}
			N -= 7;
		}
		printf("%d\n", sum);
	}
	return 0;
}
