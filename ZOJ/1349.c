#include<stdio.h>
#include<string.h>

int main(){
	long double pl[7]= {1.0/16, 0, 1.0/8, 3.0/8, 1.0/4, 1.0/8, 1.0/16}, prob[2][121], win, tie, loss;
	memset(prob, 0, sizeof(int)*121*2);
	int rnd=1, st=57, ed=63, M = 60, N = 3, p, i, t;
	for(p=st; p<=ed; p++)
		prob[1][p] = pl[p-st];

	tie = prob[1][60] * 100;
	win = 0;
	loss = 0;
	for(p=st; p<M; p++)
		loss += prob[1][p];
	for(p=M+1; p<=ed; p++)
		win += prob[1][p];
	win *= 100;
	loss *= 100;

	printf("Round   A wins    B wins    Tie\n");
	printf("%5d%10.4Lf%%%9.4Lf%%%9.4Lf%%\n", rnd, win, loss, tie);

	for(rnd=2; rnd<=20; rnd++){
		t = rnd%2;
		for(p=0; p<121; p++)
			prob[t][p] = 0;
		st = M-3*(rnd-1);
		ed = M+3*(rnd-1);
		for(i=st; i<=ed; i++){
			for(p=0; p<7; p++){
				prob[t][i+p-N] += pl[p]*prob[1-t][i];
			}
		}
		win = 0;
		loss = 0;
		tie = prob[t][M] * 100;
		for(p=st-3; p<M; p++)
			loss += prob[t][p];
		for(p=M+1; p<=ed+3; p++)
			win += prob[t][p];
		win *= 100;
		loss *= 100;
		printf("%5d%10.4Lf%%%9.4Lf%%%9.4Lf%%\n", rnd, win, loss, tie);
	}

	return 0;
}

