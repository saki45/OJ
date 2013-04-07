#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(const void *p1, const void *p2){
	return *(int*)p2 - *(int*)p1;
}

int main(){
	int n, a[100], i;
	double ans;
	while(scanf("%d", &n)!=EOF){
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		if(n == 1){
			ans = a[0];
		}
		else{
			qsort(a, n, sizeof(int), compare);
			ans = 2*sqrt(a[0]*a[1]);
			for(i=2; i<n; i++)
				ans = 2*sqrt(ans*a[i]);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
