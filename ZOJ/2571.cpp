#include<string>
#include<iostream>

using namespace std;

int getNum(string s, int p){
	int num = 0;
	while(s[p]>='0' && s[p]<='9' && p<s.size()){ 
		num = num*10+s[p]-'0';
		p++;
	}
	return num;
}

int findRp(string s, int p){
	int nlp=0;
	while(p<s.size()){
		if(s[p]=='(')
			nlp++;
		if(s[p]==')'){
			nlp--;
			if(nlp == 0)
				return p;
		}
		p++;
	}

}

string solve(string s, int st, int ed){
	string ans;
	int num, rp;
	for(int i=st; i<=ed; ){
		if(s[i]>='0' && s[i]<='9'){
			num = getNum(s, i);
			while(s[i]>='0' && s[i]<='9')
				i++;
			if(s[i] == '('){
				rp = findRp(s, i);
				string tmp = solve(s, i+1, rp-1);
				i = rp+1;
				while(num--)
					ans += tmp;
			}
			else{
				ans.append(num, s[i]);
				i++;
			}
		}
		else{
			ans.append(1, s[i]);
			i++;
		}
	}
	return ans;
}

int main(){
	int T;
	string s, ans;
	cin >> T;
	while(T--){
		cin >> s;
		ans = solve(s, 0, s.size()-1);
		cout << ans << endl;
	}
	return 0;
}
