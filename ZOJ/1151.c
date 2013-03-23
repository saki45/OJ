#include<stdio.h>

int main(){
	int nBlock, nInstance, p, q, r;
	char buf[1000], tmp;

	scanf("%d", &nBlock);
	while(nBlock>0){
		scanf("%d\n", &nInstance);
		while(nInstance>0){

			fgets(buf, sizeof(buf), stdin);
			//printf("%s", buf);
			p = 0;

			while(1){
				while(!((buf[p]>='A' && buf[p] <= 'Z') || (buf[p]>='a' && buf[p] <= 'z'))){
					printf("%c", buf[p]);
					p++;
				}

				if(buf[p] == '\n')
					break;

				q = p;
				while((buf[q]>='A' && buf[q] <= 'Z') || (buf[q]>='a' && buf[q] <= 'z'))
					q++;
				
				r = q-1;
				while(p < r){
					tmp = buf[p];
					buf[p] = buf[r];
					buf[r] = tmp;
					p++;
					r--;
				}
				p = q;
			}
			printf("%s", buf);
			nInstance--;
		}

		nBlock--;
	}
	return 0;
}
