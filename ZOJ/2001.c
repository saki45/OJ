#include<stdio.h>
#include<string.h>

void reverseNum(char *num, int l){
	if(l == 1)
		return;
	int p = 0;
	l -= 1;
	char tmp;
	while(p < l){
		tmp = num[p];
		num[p++] = num[l];
		num[l--] = tmp;
	}
}

void reverseAdd(char *num1, char *num2, int l1, int l2, char *buf2){
	int l = l1>l2?l1+1:l2+1;
	int p1=l1-1, p2=l2-1, p=0, carry = 0;
	int t1, t2, t;
	char tmp;
	buf2[l] = '\0';

	while(p1>=0 && p2>=0){
		t1 = (int)(num1[p1--] - '0');
		t2 = (int)(num2[p2--] - '0');
		t = t1 + t2 + carry;
		if(t < 10){
			carry = 0;
		}
		else{
			t = t % 10;
			carry = 1;
		}
		buf2[p++] = (char)(t+'0');
	}
	while(p1>=0){
		t1 = (int)(num1[p1--] - '0');
		t = t1+carry;
		if(t < 10){
			carry = 0;
		}
		else{
			t = t % 10;
			carry = 1;
		}
		buf2[p++] = (char)(t+'0');
	}
	while(p2>=0){
		t2 = (int)(num2[p2--] - '0');
		t = t2+carry;
		if(t < 10){
			carry = 0;
		}
		else{
			t = t % 10;
			carry = 1;
		}
		buf2[p++] = (char)(t+'0');
	}
	if(carry == 1)
		buf2[p] = (char)(carry+'0');
	while(buf2[p] == '0' && p > 0)
		p--;
	buf2[p+1] = '\0';
}

int main(){
	int N, l1, l2;
	char buf[10000], buf2[10000], *num1, *num2, *pBuf;
	scanf("%d\n", &N);

	while(N > 0){
		fgets(buf, sizeof(buf), stdin);
		pBuf = buf;
		num1 = strtok(pBuf, " \n");
		num2 = strtok(NULL, " \n");
		l1 = strlen(num1);
		l2 = strlen(num2);
		reverseNum(num1, l1);
		reverseNum(num2, l2);
		reverseAdd(num1, num2, l1, l2, buf2);
		printf("%s\n", buf2);

		N--;
	}
	return 0;
}
