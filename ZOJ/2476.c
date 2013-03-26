#include<stdio.h>
#include<string.h>

void resetSum(char sum[]){
	int i=0;
	for(i=0; i<25; i++)
		sum[i] = '0';
	sum[2] = '.';
	for(i=6; i<25; i+=4)
		sum[i] = ',';
}

void reverseSum(char sum[], int l){
	int i=0, j = l-1;
	char tmp;
	while(i<j){
		tmp = sum[i];
		sum[i++] = sum[j];
		sum[j--] = tmp;
	}
	sum[l] = '\0';
}

int main(){
	int N, l, lb, i, j, digit, carry, k;
	scanf("%d", &N);
	getchar();
	char sum[25], buf[25];
	resetSum(sum);
	while(N > 0){
		l = 3;
		while(N--){
			fgets(buf, sizeof(buf), stdin);
			lb = strlen(buf)-1;
			i = 0;
			j = lb-1;
			carry = 0;
			while(i<2){
				digit = sum[i]- '0' + buf[j--] - '0' + carry;
				carry = digit/10;
				digit = digit%10;
				sum[i++] = digit+'0';
			}
			i = 3;
			j = lb-4;
			k = 1;
			while(j>0){
				if(k == 4){
					i++;
					j--;
					k=1;
				}
				else{
					digit = sum[i]-'0'+buf[j--]-'0'+carry;
					carry = digit/10;
					digit = digit%10;
					sum[i++] = digit+'0';	
					k++;
				}
			}
			while(carry){
				if(k == 4){
					i++;
					k=1;
				}
				else{
					digit = sum[i]-'0'+carry;
					carry = digit/10;
					digit = digit%10;
					sum[i++] = digit+'0';
					k++;
				}
			}
			if(l<i)
				l = i;
		}

		reverseSum(sum, l);
		printf("$%s\n", sum);		
		scanf("%d", &N);
		getchar();
		resetSum(sum);
	}

	return 0;
}
