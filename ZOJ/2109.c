#include<stdio.h>
#include<stdlib.h>

struct record{
	int J;
	int F;
	double v;
};

int isEqual(double d1, double d2){
	if((d1-d2)*(d1-d2) < 0.00000001)
		return 1;
	else
		return 0;
}

int compare(const void *p1, const void *p2){
	const struct record *pp1 = p1;
	const struct record *pp2 = p2;
	if(pp1->v > pp2->v)
		return -1;
	if(isEqual(pp1->v, pp2->v))
		return 0;
	if(pp1->v < pp2->v)
		return 1;
}


int main(){
	int M, N, F, J, p;
	struct record r[1000];
	double sum;

	scanf("%d%d", &M, &N);
	while(M!=-1 && N!=-1){
		p = 0;
		while(p<N){
			scanf("%d%d", &J, &F);
			r[p].J = J;
			r[p].F = F;
			r[p].v = (J*1.0) / F;
			p++;
		}
		qsort(r, N, sizeof(struct record), compare);

		p = 0;
		sum = 0;
		while(p<N && M>0){
			if(r[p].F <= M){
				M -= r[p].F;
				sum += r[p].J;
			}
			else{
				sum += r[p].J*(M*1.0/r[p].F);
				M = 0;
			}
			p++;
		}
		printf("%.3lf\n", sum);
		scanf("%d%d", &M, &N);
	} 

	return 0;
}
