#include<stdio.h>
#include<math.h>

void printResult(char ch, double rt, int count){
	printf("Triangle #%d\n", count);
	if(rt >= 0)
		printf("%c = %.3f\n\n", ch, rt);
	else
		printf("Impossible.\n\n");
}

int main(){
	int a, b, c, count;
	double rt;
	char ch;
	count = 1;

	while(1){
		scanf("%d%d%d", &a, &b, &c);
		if(a ==0 && b==0 && c==0)
			break;
		if(a == -1){
			rt = (c*c - b*b)*1.0;
			ch = 'a';
			}
		else if(b == -1){
			rt = (c*c - a*a)*1.0;
			ch = 'b';
		}
		else if(c == -1){
			rt = (a*a + b*b)*1.0;
			ch = 'c';
		}
		else{
			rt = -1;
		}

		if(rt > 0){
			printResult(ch, sqrt(rt), count);
		}
		else{
			printResult(ch, rt, count);
		}
		count ++;
	}
	return 0;
}
