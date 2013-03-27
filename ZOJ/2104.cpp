#include<cstdio>
#include<string>
#include<map>

using namespace std;

int main(){
	int N, p, cur, curMax;
	char buf[20];
	string str;
	map<string, int> mp;
	map<string, int>::iterator it;

	scanf("%d", &N);
	getchar();
	while(N > 0){
		mp.clear();
		curMax = 0;
		for(p=0; p<N; p++){
			scanf("%s", buf);
			str = buf;
			if(mp.find(str) != mp.end()){
				cur = mp[str]+1;
				if(cur > curMax)
					curMax = cur;
				mp[str] = cur;
			}
			else{
				cur = 1;
				mp[str] = 1;
				if(curMax == 0)
					curMax = 1;
			}
		}
		for(it = mp.begin(); it!=mp.end(); it++){
			if(it->second == curMax){
				printf("%s\n", (it->first).c_str());
				break;
			}
		}
		scanf("%d", &N);
		getchar();
	}
	return 0;
}
