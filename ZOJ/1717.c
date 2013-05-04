// This code is WA

#include<stdio.h>
#include<string.h>

char tmp1[150], tmp2[150];

int isNumber(char ch){
	return ch>='0' && ch<='9';
}

int traceBack(char buf[][75], int prev[][75], int l[][75], int r, int c){
	int r1=r-1, r2=r, c1=c, c2=c-1, res=1, v1, v2, ll, i=0;
	ll = l[r][c] - 1;
	while(ll--){
		tmp1[i] = buf[r1][c1];
		tmp2[i] = buf[r2][c2];
		i++;

		if(prev[r1][c1] == 1)
			r1--;
		else
			c1--;

		if(prev[r2][c2] == 1)
			r2--;
		else
			c2--;

		if(r1 == r2 && c1 == c2)
			break;
	}
	i--;
	while(i>=0 && tmp1[i] == tmp2[i]){
		i--;
	}
	if(i<0)
		res = 1;
	else{
		if(tmp1[i] > tmp2[i])
			res = 1;
		else
			res = 2;
	}
	return res;
}

int main(){
	char buf[75][75], res[150][150];
	int prev[75][75], l[75][75], nMax, lMax, r, c, i, j, tb, rres[150], cres[150], out[150];

	while(scanf("%d%d", &c, &r) && (r+c)){
		getchar();

		memset(rres, 0, sizeof(rres));
		memset(cres, 0, sizeof(cres));

		memset(prev, 0, sizeof(prev));
		memset(l, 0, sizeof(l));
		lMax = 0;

		for(i=0; i<r; i++)
			fgets(buf[i], 75, stdin);

		if(isNumber(buf[0][0])){
			prev[0][0] = -1;
			l[0][0] = 1;
			lMax = 1;
		}

		for(i=1; i<r; i++){
			if(isNumber(buf[i][0])){
				if(l[i-1][0]>0){
					prev[i][0] = 1;
					l[i][0] = l[i-1][0]+1;
				}
				else{
					prev[i][0] = -1;
					l[i][0] = 1;
				}

				if(lMax < l[i][0]){
					lMax = l[i][0];
				}
			}
		}

		for(j=1; j<c; j++){
			if(isNumber(buf[0][j])){
				if(l[0][j-1]>0){
					prev[0][j] = 2;
					l[0][j] = l[0][j-1]+1;
				}
				else{
					prev[0][j] = -1;
					l[0][j] = 1;
				}

				if(lMax < l[0][j]){
					lMax = l[0][j];
				}
			}
		}

		for(i=1; i<r; i++){
			for(j=1; j<c; j++){
				if(isNumber(buf[i][j])){
					if(l[i-1][j] > l[i][j-1]){
						prev[i][j] = 1;
						l[i][j] = l[i-1][j]+1;
					}
					else if(l[i-1][j] < l[i][j-1]){
						prev[i][j] = 2;
						l[i][j] = l[i][j-1]+1;
					}
					else{
						if(l[i][j-1]){
							l[i][j] = l[i-1][j]+1;
							tb = traceBack(buf, prev, l, i, j);
							prev[i][j] = tb;
						}
						else{
							prev[i][j] = -1;
							l[i][j] = 1;
						}
					}
					if(l[i][j] > lMax){
						lMax = l[i][j];
					}
				}
			}
		}

		int rtmp, ctmp, ll;
		nMax = 0;
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				if(l[i][j] == lMax){
					rres[nMax]= i;
					cres[nMax] = j;
					rtmp = i;
					ctmp = j;
					ll = lMax;
					while(ll--){
						res[nMax][ll] = buf[rtmp][ctmp];
						if(prev[rtmp][ctmp] == 1)
							rtmp--;
						else
							ctmp--;
					}
					nMax++;
				}
			}
		}

		memset(out, 0, sizeof(out));
		if(nMax == 1)
			i = nMax-1;
		else{
			tb = nMax;
			char curMax;
			for(j=0; j<lMax; j++){
				curMax = 0;
				for(i=0; i<nMax; i++){
					if(out[i] == 0)
						if(curMax < res[i][j])
							curMax = res[i][j];
				}

				for(i=0; i<nMax; i++){
					if(out[i] == 0 && res[i][j] < curMax){
						out[i] = 1;
						tb--;
					}
				}
				if(tb == 1)
					break;
			}

			i = 0;
			while(out[i]){
				i++;
			}
		}

		j = 0;
		while(res[i][j] == '0' && j < lMax)
			j++;
		if(j == lMax)
			j--;
		while(j<lMax){
			printf("%c", res[i][j]);
			j++;
		}
		printf("\n");

	}
	return 0;
}
