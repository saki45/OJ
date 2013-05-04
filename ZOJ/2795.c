#include<stdio.h>
#include<string.h>

int main(){
	int i, p[100002], ip[100002], rec[100002], N, tmp, isam;
	memset(rec, 0, sizeof(rec));
	while(scanf("%d", &N) && N){
		isam = 1;

		for(i=1; i<=N; i++){
			scanf("%d", &tmp);

			if(isam){
				p[i] = tmp;
				ip[tmp] = i;
				rec[tmp] = 1;
				if(rec[i]){
					if(p[i] != ip[i])
						isam = 0;
				}
			}
		}

		if(isam)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");

		memset(rec, 0, (N+1)*4);
	}
	return 0;
}
