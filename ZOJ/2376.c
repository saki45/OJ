#include<stdio.h>

int main(){
	int poll, N, nAnt, pos, cMin, cMax, i, tmpMin, tmpMax;
	scanf("%d", &N);
	while(N--){
		scanf("%d%d", &poll, &nAnt);
		cMin = 0;
		cMax = 0;
		for(i=0; i<nAnt; i++){
			scanf("%d", &pos);
			if(pos <= poll/2){
				tmpMin = pos;
				tmpMax = poll - pos;
			}
			else{
				tmpMin = poll - pos;
				tmpMax = pos;
			}
			if(tmpMin > cMin)
				cMin = tmpMin;
			if(tmpMax > cMax)
				cMax = tmpMax;
		}
		printf("%d %d\n", cMin, cMax);
	}
	return 0;
}
