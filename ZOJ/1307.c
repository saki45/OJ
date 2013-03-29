#include<stdio.h>

int main(){
	int num[7], i, sum, tmp, left, empty4;
	while(1){
		for(i=1; i<=6; i++)
			scanf("%d", &num[i]);

		sum = num[6] + num[5];
		if(num[5] > 0)
			if(num[5]*11 >= num[1])
				num[1] = 0;
			else
				num[1] -= num[5]*11;

		sum += num[4];
		if(num[4] > 0)
			if(num[4]*5 >= num[2]){
				empty4 = num[4] - num[2]/5;
				if(num[2]%5 != 0){
					left = (5 - num[2]%5) * 4;
					empty4 -= 1;
					if(num[1] < left)
						num[1] = 0;
					else
						num[1] -= left;
				}
				num[2] = 0;

				if(empty4*20 >= num[1])
					num[1] = 0;
				else
					num[1] -= empty4*20;
			}
			else
				num[2] -= num[4]*5;

		sum += num[3]/4;
		if(num[3] > 0)
			if(num[3] % 4 != 0){
				left = 7 - (num[3] % 4)*2;
				sum += 1;
				if(num[2] <left){
					left = 36 - ((num[3]%4)*9 + num[2]*4);
					num[2] = 0;
					if(num[1] <left)
						num[1] = 0;
					else
						num[1] -= left;
				}
				else{
					num[2] -= left;
					left = 36 - ((num[3]%4)*9 + left*4);
					if(num[1] < left)
						num[1] = 0;
					else
						num[1] -= left;
				}
			}

		sum += num[2] / 9;
		if(num[2] > 0)
			if(num[2] % 9 != 0){
				sum += 1;
				left = 36 - (num[2]%9)*4;
				if(num[1] < left)
					num[1] = 0;
				else
					num[1] -= left;
			}

		sum += num[1]/36;
		if(num[1] % 36)
			sum += 1; 

		if(sum == 0)
			break;
		else
			printf("%d\n", sum);
	}
	return 0;
}
