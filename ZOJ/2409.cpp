#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct card{
	int num, color, value;
	char name[4];

	bool operator < (const card &o) const{
		return value < o.value;
	}

	bool operator > (const card &o) const{
		return value > o.value;
	}

	void setColor(char ch){
		switch(ch){
			case 'C':
				color = 1;
				break;
			case 'D':
				color = 2;
				break;
			case 'H':
				color = 3;
				break;
			case 'S':
				color = 4;
				break;
		}
	}

	void init(char buf[]){
		strcpy(name, buf);
		if(strlen(buf) == 3){
			num = 10;
			setColor(buf[2]);
			value = num*10+color;
			return;
		}

		if(buf[0] == 'A')
			num = 1;
		else if(buf[0] == 'J')
			num = 11;
		else if(buf[0] == 'Q')
			num = 12;
		else if(buf[0] == 'K')
			num = 13;
		else
			num = buf[0] - '2' + 2;
		setColor(buf[1]);
		value = num*10+color;
	}
};

int isSolution(vector<card> vv){
	if(vv[0].color != vv[1].color)
		return 0;

	int res = 0, minIdx, noOrder = 0;
	if(vv[2]<vv[3] && vv[2]<vv[4]){
		minIdx = 2;
		if(vv[3] > vv[4])
			noOrder = 1;
	}
	else if(vv[3]<vv[2] && vv[3]<vv[4]){
		minIdx = 3;
		if(vv[2] > vv[4])
			noOrder = 1;
	}
	else{
		minIdx = 4;
		if(vv[2] > vv[3])
			noOrder = 1;
	}

	res = minIdx-1+noOrder*3;
	if(((vv[1].num-1+res)%13+1) == vv[0].num)
		return 1;
	else
		return 0;
}

int main(){
	vector<card> vv;
	int T, nCase;
	char buf[4];
	card tmp;
	scanf("%d", &T);
	nCase = 1;
	while(T--){
		vv.erase(vv.begin(), vv.end());

		for(int i=0; i<5; i++){
			scanf("%s", buf);
			tmp.init(buf);
			vv.push_back(tmp);
		}

		sort(vv.begin(), vv.end());
		while(!isSolution(vv)){
			next_permutation(vv.begin(), vv.end());
		}

		printf("Problem %d:", nCase++);
		for(int i=0; i<5; i++){
			printf(" %s", vv[i].name);
		}
		printf("\n");
	}
	return 0;
}
