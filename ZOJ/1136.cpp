// This code is WA

#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<stdlib.h>

using namespace std;

struct nums{
	string s;
	int remain;
	bool isZero;
};

int main(){
	int N, M, exist[10], num[10], tmp, p;
	bool nonExist, isFind;
	queue<nums> q;
	while(scanf("%d", &N)!=EOF){
		isFind = false;
		memset(exist, 0, sizeof(exist));
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			scanf("%d", &tmp);
			exist[tmp] = 1;
		}
		p = 0;
		for(int i=0; i<10; i++){
			if(exist[i])
				num[p++] = i;
		}
		tmp = N%10;
		nonExist = false;

		if(num[0] == 0 && M == 1){
			printf("0\n");
			continue;
		}

		switch(tmp){
			case 0:
				if(!exist[0])
					nonExist = true;
				break;
			case 2:
			case 4:
			case 6:
			case 8:
				if(!exist[0] && !exist[2] && !exist[4] && !exist[6] && !exist[8])
					nonExist = true;
				break;
			case 5:
				if(!exist[0] && !exist[5])
					nonExist = true;
				break;				
		}
		if(nonExist){
			printf("0\n");
			continue;
		}

		while(!q.empty())
			q.pop();
		for(int i=0; i<M; i++){
			nums tmpNum;
			char ch = num[i]+'0';
			tmpNum.s = ch;
			tmpNum.remain = num[i]%N;
			tmpNum.isZero = num[i]==0;
			q.push(tmpNum);
			if(tmpNum.remain == 0){
				printf("%s\n", tmpNum.s.c_str());
				isFind = true;
				break;
			}
		}
		if(isFind)
			continue;

		while(true){
			nums tmpNum = q.front();
			if(!tmpNum.isZero){
				for(int i=0; i<M; i++){
					nums nTmp;
					char ch = num[i]+'0';
					nTmp.s = tmpNum.s + ch;
					nTmp.remain = (tmpNum.remain*10+num[i])%N;
					nTmp.isZero = false;
					if(nTmp.remain == 0){
						printf("%s\n", nTmp.s.c_str());
						isFind = true;
						break;
					}
					q.push(nTmp);
				}
			}
			q.pop();
			if(isFind || tmpNum.s.size() > 5000)
				break;
		}
		if(!isFind)
			printf("0\n");
	}
	return 0;
}
