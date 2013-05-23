#include<stdio.h>
#include<string.h>

int main(){
	int T, label[10001], N, i, j, curMax, x, y1, y2;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		memset(label, 0, sizeof(label));
		for(i=0; i<N; i++){
			scanf("%d%d%d", &x, &y1, &y2);

			for(j=y1; j<=y2; j++)
				label[j]++;
		}

		curMax = 0;
		for(i=0; i<10001; i++){
			if(label[i] > curMax)
				curMax = label[i];
		}
		printf("%d\n", curMax);
	}
	return 0;
}
