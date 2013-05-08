#include<stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))

typedef unsigned long long LL;

int main(){
	int i, j, k, n, N;
	LL p1, p2, p3, h[100000], a1, a2, a3, m;
	
	while(~scanf("%llu%llu%llu%d", &p1, &p2, &p3, &N)){
		i = 0;
		j = 0;
		k = 0;
		n = 1;
		h[0] = 1;
		while(n<=N){
			a1 = h[i]*p1;
			a2 = h[j]*p2;
			a3 = h[k]*p3;
			m = min(a1, min(a2, a3));
			if(m == a1)
				i++;
			else if(m == a2)
				j++;
			else
				k++;
			if(m != h[n-1])
				h[n++] = m;
		}
		printf("%llu\n", h[N]);
	}
	return 0;
}
