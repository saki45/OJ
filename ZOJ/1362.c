#include<stdio.h>
#include<string.h>

int main(){
	int m, n, hash[1001], p, win, nLarger, count, tmp, nCard;

	scanf("%d%d", &m, &n);
	count = 1;
	while(m !=0 && n!=0){
		memset(hash, 0, 1001*sizeof(int));
		win = 0;
		nLarger = 0;
		
		for(p=0; p<n; p++){
			scanf("%d", &tmp);
			hash[tmp] = 1;
		}
		
		p = n*m;
		nCard = 0;
		while(nCard < n){
			if(hash[p] == 0)
				nLarger++;
			else{
				nCard++;
				if(nLarger > 0)
					nLarger --;
				else
					win++;
			}
			p--;
		}


		printf("Case %d: %d\n", count, win);
		count++;
		scanf("%d%d", &m, &n);
	}
	return 0;
}
