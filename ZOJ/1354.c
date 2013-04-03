#include<stdio.h>

int solve(int *s, int *f, int i, int j){
	if(i==4 && j==6){
		if( (((*s)&(1<<(6*i+j-1)))==0) && (((*s)&(1<<(6*(i-1)+j-1)))==0) && (((*s)&(1<<(6*i+j-2)))==0) )
			return 1;
		else
			return 0;
	}
	if(j == 6)
		return solve(s, f, i+1, 0);

	int res0, res1;
	if(i == 0){
		res0 = solve(s, f, i, j+1);
		if(!res0){
			*s ^= 1<<j;
			*s ^= 1<<(6+j);
			if(j > 0)
				*s ^= 1<<(j-1);
			if(j < 5)
				*s ^= 1<<(j+1);
			*f ^= 1<<j;
			res1 = solve(s, f, i, j+1);
			if(!res1){
				*s ^= 1<<j;
				*s ^= 1<<(6+j);
				if(j > 0)
					*s ^= 1<<(j-1);
				if(j < 5)
					*s ^= 1<<(j+1); 
				*f ^= 1<<j;
				return 0;
			}
			else
				return 1;
		}
		else
			return 1;
	}
	else{
		if(((*s)&(1<<(6*(i-1)+j))) == 0){
			if(i == 4 && j > 0){
				if(((*s)&(1<<(6*i+j-1))) == 0)
					res0 = solve(s, f, i, j+1);
				else
					res0 = 0;
				}
			else
				res0 = solve(s, f, i, j+1);
		}
		else
			res0 = 0;

		if(!res0){
			if(((*s)&(1<<(6*(i-1)+j))) == 0)
				return 0;
			if(i == 4 && j > 0)
				if(((*s)&(1<<(6*i+j-1))) ==0)
					return 0;

			*s ^= 1<<(6*i+j);
			*s ^= 1<<(6*(i-1)+j);
			if(i < 4)
				*s ^= 1<<(6*(i+1)+j);
			if(j > 0)
				*s ^= 1<<(6*i+j-1);
			if(j < 5)
				*s ^= 1<<(6*i+j+1);
			*f ^= 1<<(6*i+j);
			res1 = solve(s, f, i, j+1);
			if(!res1){
				*s ^= 1<<(6*i+j);
				*s ^= 1<<(6*(i-1)+j);
				if(i < 4)
					*s ^= 1<<(6*(i+1)+j);
				if(j > 0)
					*s ^= 1<<(6*i+j-1);
				if(j < 5)
					*s ^= 1<<(6*i+j+1);
				*f ^= 1<<(6*i+j);
				return 0;
			}
			else
				return 1;
		}
		else
			return 1;
	}
	return 0;
}

int main(){
	int N, s, f, i, j, count, tmp;
	scanf("%d", &N);
	count = 1;
	while(N--){
		s = 0;
		f = 0;
		for(i=0; i<5; i++)
			for(j=0; j<6; j++){
				scanf("%d", &tmp);
				if(tmp == 1)
					s |= 1<<(6*i+j);
			}
		solve(&s, &f, 0, 0);
		printf("PUZZLE #%d\n", count);
		count++;
		for(i=0; i<5; i++){
			tmp = f & (1<<(6*i));
			if(tmp)
				tmp = 1;
			printf("%d", tmp);
			for(j=1; j<6; j++){
				tmp = f & (1<<(6*i+j));
				if(tmp > 0)
					tmp = 1;
				printf(" %d", tmp);
			}
			printf("\n");
		}
	}
	return 0;
}
