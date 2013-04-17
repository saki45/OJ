#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comp(const void *a, const void *b){
	const char *ca, *cb;
	ca = a;
	cb = b;
	if(*ca<*cb)
		return -1;
	else if(*ca>*cb)
		return 1;
	else
		return 0;
}

void nextPermutation(char str[]){
	int p = 4, q=4;
	while(str[p] < str[p-1] && p>=0)
		p--;
	p--;
	if(p == -1)
		return;
	while(str[q] < str[p])
		q--;

	char tmp = str[q];
	str[q] = str[p];
	str[p] = tmp;
	if(p < 3)
		qsort(str+p+1, 4-p, sizeof(char), comp);
}

void getPermutation(char str[][5]){
	char *strtmp = "ABCDE";
	memcpy(str[0], strtmp, 5);
	int i;
	for(i=1; i<120; i++){
		memcpy(str[i], str[i-1], 5);
		nextPermutation(str[i]);
	}
}

void generateOrders(int orders[][5], char str[][5]){
	int p, i;
	for(p=0; p<120; p++){
		for(i=0; i<5; i++){
			orders[p][str[p][i]-'A'] = i;
		}
	}
}

int main(){
	int N, orders[120][5], i, j, p, q, tmp, tmpi, rank[120], curMin, curMinIdx, in[100][5];
	char str[120][5];
	getPermutation(str);
	generateOrders(orders, str);

	char buf[10];
	while(scanf("%d", &N) && N){
		for(i=0; i<N; i++){
			scanf("%s", buf);
			tmp = 0;
			for(p=0; p<5; p++)
				in[i][buf[p]-'A'] = p;
		}

		memset(rank, 0, sizeof(rank));

		for(i=0; i<120; i++){
			for(j=0; j<N; j++){
				tmp = 0;
				for(p=0; p<4; p++){
					for(q=p+1; q<5; q++){
						tmpi = (orders[i][p]-orders[i][q])*(in[j][p]-in[j][q]);
						if(tmpi<0)
							tmp++;
					}
				}
				rank[i] += tmp;
			}
		}

		curMin = rank[0];
		curMinIdx = 0;
		for(i=1; i<120; i++){
			if(curMin > rank[i]){
				curMin = rank[i];
				curMinIdx = i;
			}
		}

		for(i=0; i<5; i++)
			printf("%c", str[curMinIdx][i]);
		printf(" is the median ranking with value %d.\n", curMin);
	}
	return 0;
}
