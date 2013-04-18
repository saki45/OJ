#include<string.h>
#include<stdio.h>

int main(){
	char name[200], wname[200];
	int mSolved, mPenalty, solved, pen, sub[4], time[4], N, i;
	scanf("%d", &N);
	mSolved = 0;
	mPenalty = 9999999;
	while(N--){
		scanf("%s", name);
		for(i=0; i<4; i++){
			scanf("%d", &sub[i]);
			scanf("%d", &time[i]);
		}

		solved = 0;
		pen = 0;
		for(i=0; i<4; i++){
			if(time[i] != 0){
				solved++;
				pen += time[i] + 20*(sub[i]-1);
			}
		}

		if(solved > mSolved || (solved==mSolved && pen<mPenalty)){
			mSolved = solved;
			mPenalty = pen;
			strcpy(wname, name);
		}
	}
	printf("%s %d %d\n", wname, mSolved, mPenalty);

	return 0;
}
