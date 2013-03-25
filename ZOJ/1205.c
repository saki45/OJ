#include<stdio.h>
#include<string.h>

int main(){
	char buf1[104], buf2[104], buf[104], tmp;
	char hashia[20];
	int  hashai[128];
	int i=0, l1, l2, l, p1, p2, p, carry, d1, d2, d;

	for(i=0; i<10; i++){
		hashia[i] = '0'+i;
	}
	for(i=10; i<20; i++){
		hashia[i] = 'a'+i-10;
	}
	for(i='0'; i<='9'; i++){
		hashai[i] = i-'0';
	}
	for(i='a'; i<='j'; i++){
		hashai[i] = i-'a'+10;
	}

	while(fgets(buf1, sizeof(buf1), stdin) != NULL){
		fgets(buf2, sizeof(buf2), stdin);

		l1 = strlen(buf1);
		l2 = strlen(buf2);
		p1 = l1-2;
		p2 = l2-2;
		carry = 0;
		p = 0;

		while(p1>=0 || p2>=0){
			d1 = p1>=0?hashai[(int)buf1[p1--]]:0;
			d2 = p2>=0?hashai[(int)buf2[p2--]]:0;
			d = d1+d2+carry;

			if(d < 20){
				carry = 0;
			}
			else{
				carry = 1;
				d = d % 20;
			}
			buf[p++] = hashia[d];
		}

		if(carry > 0){
			buf[p++] = hashia[carry];
		}

		l = p;
		buf[l] = '\n';
		buf[l+1] = '\0';
		for(p1=0, p2=l-1; p1<p2; p1++, p2--){
			tmp = buf[p1];
			buf[p1] = buf[p2];
			buf[p2] = tmp;
		}

		printf("%s", buf);
	}
	return 0;
}
