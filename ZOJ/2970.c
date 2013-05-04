#include<stdio.h>
#include<string.h>

int main(){
	int T, n, i, curMax, curMin, notFaster, tmp;
	char str[10];

	scanf("%d", &T);
	while(T--){
		scanf("%s%d", str, &n);
		scanf("%d", &curMax);
		curMin = curMax;

		notFaster = strcmp(str, "Faster");

		for(i=1; i<n; i++){
			scanf("%d", &tmp);
			if(notFaster){
				if(tmp>curMax)
					curMax = tmp;
			}
			else{
				if(tmp<curMin)
					curMin = tmp;
			}
		}

		if(notFaster)
			printf("%d\n", curMax);
		else
			printf("%d\n", curMin);

	}
	return 0;
}
