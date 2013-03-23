#include<stdio.h>

void displayResult(int res){
	if(res){
		printf("SAME\n");
	}
	else{
		printf("DIFFERENT\n");
	}
}

char findNext(char *buf, int *p){
	char *tmp = buf + *p;
	while(*tmp != ' ')
		tmp++;
	tmp++;
	*p = tmp - buf;
	return *tmp;
}

int main(){
	char buf1[60], buf2[60], ch1, ch2;
	int N, N1, N2, p1, p2, isSame;
	scanf("%d", &N);

	while(N > 0){
		scanf("%d\n", &N1);
		fgets(buf1, sizeof(buf1), stdin);
		scanf("%d\n", &N2);
		fgets(buf2, sizeof(buf2), stdin);

		if(N1 != N2){
			displayResult(0);
		}
		else{
			p1 = 0;
			p2 = 0;
			ch1 = buf1[p1];
			ch2 = buf2[p2];
			isSame = 1;

			if(ch1 != ch2)
				displayResult(0);
			else{
				N1--;
				while(N1 > 0){
					ch1 = findNext(buf1, &p1);
					ch2 = findNext(buf2, &p2);
					if(ch1 != ch2){
						isSame = 0;
						break;
					}
					N1 --;
				}
				displayResult(isSame);
			}
		}
		N--;
	}
}
