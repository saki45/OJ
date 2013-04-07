//This is WA code. I cannot find which part goes wrong. ><

#include<stdio.h>
#include<math.h>

#define eps 0.000000000001

int isEqual(double i, double j){
	if(fabs(i-j) < eps)
		return 1;
	else
		return 0;
}
 int gcd(int i, int j){
	int tmp;
	if(i < j){
		tmp = i;
		i =j;
		j = tmp;
	}
	while(j != 0){
		tmp = i;
		i = j;
		j = tmp%i;
	}
	return i;
}

int main(){
	double d, diff, tmp;
	int L, i, j, ti, tj;
	while(scanf("%lf %d", &d, &L) != EOF){
		if(isEqual(d, 1.0)){
			printf("1 1\n");
			continue;
		}
		diff = 1000;
		ti=0;
		tj=0;
		for(i=1; i<=L; i++){
			j = (int)(i*d);
			if(j>L)
				break;
			tmp = j*1.0/i;
			if(fabs(tmp - d) < diff){
				diff = fabs(tmp-d);
				ti = i;
				tj = j;
			}
			j++;
			if(j <= L){
				tmp = j*1.0/i;
				if(fabs(tmp - d) < diff){
					diff = fabs(tmp-d);
					ti = i;
					tj = j;
				}
			}
		}
		int gc = gcd(tj, ti);
		if(gc != 1){
			tj = tj/gc;
			ti = ti/gc;
		}
		printf("%d %d\n", tj, ti);
	}

	return 0;
}
