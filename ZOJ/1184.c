#include<stdio.h>
#include<string.h>

int main(){
	int i, p, len, N, nImbalance, even[12], light[12], heavy[12], isLight;
	char buf[30], *left, *right, *status, ch, *str;
	scanf("%d", &N);
	getchar();
	while(N--){
		memset(even, 0, sizeof(even));
		memset(light, 0, sizeof(light));
		memset(heavy, 0, sizeof(heavy));
		nImbalance = 0;
		isLight = 0;

		for(i=0; i<3; i++){
			fgets(buf, sizeof(buf), stdin);
			str = buf;
			left = strtok(str, " \n");
			right = strtok(NULL, " \n");
			status = strtok(NULL, "\n");

			if(!strcmp(status, "even")){
				len = strlen(left);
				for(p=0; p<len; p++)
					even[(int)(left[p]-'A')] ++;
				len = strlen(right);
				for(p=0; p<len; p++)
					even[(int)(right[p]-'A')] ++;
			}
			if(!strcmp(status, "up")){
				len = strlen(left);
				for(p=0; p<len; p++)
					heavy[(int)(left[p]-'A')] ++;
				len = strlen(right);
				for(p=0; p<len; p++)
					light[(int)(right[p]-'A')] ++;
				nImbalance++;
			}
			if(!strcmp(status, "down")){
				len = strlen(left);
				for(p=0; p<len; p++)
					light[(int)(left[p]-'A')] ++;
				len = strlen(right);
				for(p=0; p<len; p++)
					heavy[(int)(right[p]-'A')] ++;
				nImbalance++;
			}
		}
		for(i=0; i<12; i++){
			if(even[i]==0){
				if(light[i] == nImbalance){
					isLight = 1;
					ch = i+'A';
					break;
				}
				if(heavy[i] == nImbalance){
					isLight = 0;
					ch = i+'A';
					break;
				}
			}
		}
		if(isLight)
			printf("%c is the counterfeit coin and it is light.\n", ch);
		else
			printf("%c is the counterfeit coin and it is heavy.\n", ch);
	}
	return 0;
}
