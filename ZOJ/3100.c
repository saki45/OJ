#include<stdio.h>

int main(){
	int n, s, cMin, cMax, i, tmp;
	while(scanf("%d", &n) && n){
		s = 0;
		cMin = 1000;
		cMax = 0;
		for(i=0; i<n; i++){
			scanf("%d", &tmp);
			s += tmp;
			if(cMin > tmp)
				cMin = tmp;
			if(cMax < tmp)
				cMax = tmp;
		}
		s = (s-cMin-cMax)/(n-2);
		printf("%d\n", s);
	}
	return 0;
}
