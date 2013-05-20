#include<stdio.h>
#include<string.h>

int ufs[100001];

int Find(int v){
	if(ufs[v] < 0)
		return ufs[v];
	else{
		int i = ufs[v], h, ni;
		while(ufs[i]>0){
			i = ufs[i];
		}
		h = i;
		i = v;
		while(ufs[i]>0){
			ni = ufs[i];
			ufs[i] = h;
			i = ni;
		}
		return h;
	}
}

void Union(int u, int v){
	if(u==v)
		return;

	int hu, hv;

	hu = Find(u);
	hv = Find(v);
	if(hu==v || hv==u)
		return;

	if(hu < 0 && hv < 0){
		ufs[v] = u;
		ufs[u] = hu+hv;
	}
	else if(hu == hv)
		return;
	else if(hu > 0 && hv < 0){
		ufs[v] = hu;
		ufs[hu] += hv;
	}
	else if(hu < 0 && hv > 0){
		ufs[u] = hv;
		ufs[hv] += hu;	
	}
	else{
		int tmp = ufs[hv];
		ufs[hv] = hu;
		ufs[hu] += tmp;
	}
}

int main(){
	int i, M, N, num, t1, t2, nCase = 1, isFirst = 1;
	char ch;
	while(scanf("%d%d", &N, &M) != EOF){
		if(!isFirst)
			printf("\n");
		if(nCase == 1)
			isFirst = 0;
		printf("Case %d:\n", nCase++);

		memset(ufs, -1, (N+1)*sizeof(int));
		getchar();
		for(i=0; i<M; i++){
			scanf("%c", &ch);
			if(ch == 'M'){
				scanf("%d%d", &t1, &t2);
				Union(t1, t2);
			}
			else{
				scanf("%d", &t1);
				num = Find(t1);
				if(num>0)
					num = ufs[num];
				printf("%d\n", (-1*num));
			}
			getchar();
		}
	}
	return 0;
}
