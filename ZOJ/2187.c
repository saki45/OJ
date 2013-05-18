#include<string.h>
#include<stdio.h>

int main(){
	int R, C, img[10][10], imout[10][10], i, j, sum;
	char buf[15], tmp;
	while(scanf("%s", buf) && strcmp(buf, "ENDOFINPUT")!=0){
		scanf("%d%d", &R, &C);
		getchar();
		for(i=0; i<R; i++){
			for(j=0; j<C; j++){
				scanf("%c", &tmp);
				img[i][j] = tmp - '0';
			}
			getchar();
		}

		for(i=0; i<R-1; i++){
			for(j=0; j<C-1; j++){
				sum = img[i][j] + img[i][j+1] + img[i+1][j] + img[i+1][j+1];
				imout[i][j] = sum/4;
			}
		}

		for(i=0; i<R-1; i++){
			for(j=0; j<C-1; j++){
				printf("%d", imout[i][j]);
			}
			printf("\n");
		}
		scanf("%s", buf);
	}
	return 0;
}
