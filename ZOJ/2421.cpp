#include<iostream>
#include<vector>
#include<set>

#define SIZE 500000

using namespace std;

int main(){
	vector<int> v;
	set<int> s;
	int tmp;

	v.push_back(0);
	s.insert(0);

	for(int i=1; i<=SIZE; i++){
		if(v[i-1]-i > 0)
			if(s.find(v[i-1]-i) == s.end())
				tmp = v[i-1]-i;
			else
				tmp = v[i-1]+i;
		else
			tmp = v[i-1]+i;
		v.push_back(tmp);
		s.insert(tmp);
	}

	while(cin>>tmp && tmp>=0){
		cout<<v[tmp]<<endl;
	}

	return 0;
}
