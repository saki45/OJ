#include<stdio.h>
#include<string.h>

int main(){
	int a[1001], b[1001], c[1001], m[2003], na, nb, nc, nm, mi, N, i, j, k;
	scanf("%d", &N);

	while(N--){
		memset(m, 0, sizeof(int)*2003);

		scanf("%d", &na);
		for(i=na-1; i>=0; i--)
			scanf("%d", &a[i]);
		scanf("%d", &nb);
		for(j=nb-1; j>=0; j--)
			scanf("%d", &b[j]);
		scanf("%d", &nc);
		for(i=nc-1; i>=0; i--)
			scanf("%d", &c[i]);

		for(i=0; i<na; i++)
			for(j=0; j<nb; j++)
				m[i+j] ^= a[i]*b[j];

		for(k=na+nb-2; k>=nc-1; k--){
			if(m[k] == 1)
				for(i=nc-1; i>=0; i--)
					m[k-(nc-1-i)] ^= c[i];
		}

		for(nm = nc-1; nm>=0; nm--)
			if(m[nm])
				break;
			
		
		printf("%d", nm+1);
		if(nm < 0)
			printf(" 0");
		for(i=nm; i>=0; i--)
			printf(" %d", m[i]);
		printf("\n");
	}
	return 0;
}
