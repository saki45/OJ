#include<stdio.h>

int main(){
	int low, high, i;
	char buf[10];
	while(scanf("%d", &i) && i){
		low = 0;
		high = 11;
		while(1){
			scanf("%s", buf);
			scanf("%s", buf);
			if(buf[0] == 'o'){
				if(low<i && i<high){
					printf("Stan may be honest\n");
				}
				else{
					printf("Stan is dishonest\n");
				}
				break;
			}
			else{
				if(buf[0] == 'h'){
					if(high > i)
						high = i;
				}
				else if(buf[0] == 'l'){
					if(low < i)
						low = i;
				}
			}
			scanf("%d", &i);
		}
	}
	return 0;
}
