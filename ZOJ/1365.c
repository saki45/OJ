#include<stdio.h>
#include<stdlib.h>

int main(){
	int sum, tmp;
	char buf[100];
	scanf("%s", buf);
	while(!(buf[0] == '#' && buf[1] == '\0')){
		sum = 0;
		while(buf[0] != '0' || buf[1] != '\0'){
			scanf("%s", buf);

			scanf("%s", buf);
			tmp = atoi(buf);
			
			scanf("%s", buf);
			switch(buf[0]){
				case 'F':
					sum += 2*tmp;
					break;
				case 'B':
					sum += tmp;
					if(tmp % 2)
						sum += 1;
					sum += tmp>>1;
					break;
				case 'Y':
					if(tmp > 500)
						sum += tmp;
					else
						sum += 500;
			}
			scanf("%s", buf);
		}
		printf("%d\n", sum);
		scanf("%s", buf);
	}
	return 0;
}
