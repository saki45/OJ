#include<cstdio>
#include<cstring>
#include<string>
#include<map>

using namespace std;

int main(){
	string fm, eng;
	map<string, string> mp;

	char buf[150], *str, *tok;
	while(1){
		fgets(buf, sizeof(buf), stdin);
		if(buf[0] == '\n')
			break;
		str = buf;
		tok = strtok(str, " \n");
		eng = tok;
		tok = strtok(NULL, " \n");
		fm = tok;
		mp[fm] = eng;
	}

	map<string, string>::iterator it;
	while(fgets(buf, sizeof(buf), stdin) != NULL){
		if(buf[0] == '\n'){
			printf("eh\n");
			continue;
		}
		str = buf;
		tok = strtok(str, " \n");
		fm = tok;

		it = mp.find(fm);
		if(it != mp.end())
			printf("%s\n", mp[fm].c_str());
		else
			printf("eh\n");
	}
	return 0;
}
