#include<stdio.h>

int main(){
	FILE *fin, *fout;
	fin = fopen("A-small-practice.in", "r");
	fout = fopen("test.out", "w");

	char buf[1000];
	while(fgets(buf, sizeof(buf), fin) != NULL){
		printf("%s", buf);
		fputs(buf, fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
