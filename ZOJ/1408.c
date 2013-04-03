#include<stdio.h>

int solve(long long M, char *buf, long long *pMin, long long *pMax, int *ans, int p, int len){
	long long base = 1<<p;
	int res, i;

	if(M == 0){
		for(i=p; i>=0; i--)
			ans[i] = 0;
		return 1;
	}

	if(p == 0){
		if(buf[len-1] == 'p' && M == 1){
			ans[0] = 1;
			return 1;
		}
		else if(buf[len-1] == 'n' && M == -1){
			ans[0] = 1;
			return 1;
		}
		else
			return 0;
	}

	if(M >= pMin[p] && M <= pMax[p]){
		ans[p] = 0;
		res = solve(M, buf, pMin, pMax, ans, p-1, len);
		if(!res){
			if(buf[len-1-p] == 'p'){
				ans[p] = 1;
				res = solve(M-base, buf, pMin, pMax, ans, p-1, len);
			}
			else{
				ans[p] = 1;
				res = solve(M+base, buf, pMin, pMax, ans, p-1, len);
			}
			if(res)
				return 1;
			else
				ans[p] = 0;
		}
		else
			return 1;
	}
	return 0;
}

int main(){
	int N, len, i, res, ans[64];
	long long M, pMin[64], pMax[64], base;
	char buf[66];

	scanf("%d", &N);
	while(N--){
		scanf("%d", &len);
		getchar();
		scanf("%s", buf);
		getchar();
		scanf("%Ld", &M);

		if(buf[len-1] == 'p'){
			pMin[0] = 0;
			pMax[0] = 1;
		}
		else{
			pMin[0] = -1;
			pMax[0] = 0;
		}

		base = 1;
		for(i=1; i<len; i++){
			base <<= 1;
			if(buf[len-1-i] == 'p'){
				pMin[i] = pMin[i-1];
				pMax[i] = pMax[i-1] + base;
			}
			else{
				pMin[i] = pMin[i-1] - base;
				pMax[i] = pMax[i-1];
			}
		}

		pMax[63] = 9223372036854775807;
		pMin[63] = -pMax[63];

		res = solve(M, buf, pMin, pMax, ans, len-1, len);
		if(res){
			for(i=len-1; i>=0; i--)
				printf("%d", ans[i]);
			printf("\n");
		}
		else
			printf("Impossible\n");

	}
	return 0;
}
