#include<stdio.h>
#include<string.h>

int main(){
	int k, m, c, r[101], req[101][10000], s[101], i, j, tmp, isOK;
	while(scanf("%d", &k) && k){
		scanf("%d", &m);
		for(i=0; i<k; i++)
			scanf("%d", &s[i]);

		if(m == 0){
			printf("yes\n");
			continue;
		}

		memset(req, 0, sizeof(req));
		for(i=0; i<m; i++){
			scanf("%d%d", &c, &r[i]);
			for(j=0; j<c; j++){
				scanf("%d", &tmp);
				req[i][tmp] = 1;
			}
		}

		isOK = 1;
		for(i=0; i<m; i++){
			for(j=0; j<k; j++){
				if(req[i][s[j]])
					r[i]--;
				if(r[i] == 0)
					break;
			}
			if(r[i]>0){
				isOK = 0;
				break;
			}
		}

		if(isOK)
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;
}
