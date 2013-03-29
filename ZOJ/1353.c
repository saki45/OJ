#include<stdio.h>
#include<string.h>

#define SIZE 300

int main(){
	int N, n, tmp, i, j, m, mid;
	long long num[SIZE][SIZE];
	memset(num, 0, sizeof(long long)*SIZE*SIZE);
	num[1][1] = 1;
	num[2][1] = 2;
	num[2][2] = 1;
	n=3;
	while(n< SIZE){
		mid = n>>1;
		for(i=n; i>mid; i--)
			num[n][i] = 1;
		if(n%2 == 0){
			num[n][mid] = num[n][mid+1] +1;
			for(i = mid-1; i>=1; i--)
				if(i <= n-2*i)
					num[n][i] = num[n][i+1] + num[n-2*i][i];
				else
					num[n][i] = num[n][i+1];
		}
		else{
			for(i = mid; i>=1; i--)
				if(i <= n-2*i)
					num[n][i] = num[n][i+1] + num[n-2*i][i];
				else
					num[n][i] = num[n][i+1];
		}
		n++;
	}

	scanf("%d", &N);
	while(N){
		printf("%d %Ld\n", N, num[N][1]);
		scanf("%d", &N);
	}
	return 0;
}
