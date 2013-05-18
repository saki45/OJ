#include<stdio.h>
#include<string.h>

int main(){
	int c, cl, cr, s, l, i, isSym;
	char buf[1010];
	while(scanf("%s", buf)!=EOF){
		l = strlen(buf);
		isSym = 0;
		for(i=0; i<l; i++){
			c = i;
			s = 1;
			while(s <= l/2){
				if(buf[(c-s+l)%l] != buf[(c+s+l)%l])
					break;
				s++;
			}

			if(s > l/2){
				c++;
				isSym = 1;
				printf("Symmetric\n");
				printf("%d\n", c);
				break;	
			}

			cl = i;
			cr = i+1;
			s = 0;
			while(s<=l/2){
				if(buf[(cl-s+l)%l] != buf[(cr+s+l)%l])
					break;
				s++;
			}
			if(s > l/2){
				cl++;
				cr++;
				isSym = 1;
				printf("Symmetric\n");
				printf("%d-%d\n", cl, cr);
				break;
			}
		}
		if(!isSym){
			printf("Not symmetric\n");
		}
	}
	return 0;
}
