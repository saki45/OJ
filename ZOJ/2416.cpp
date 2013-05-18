#include<iostream>
#include<string>
#include<queue>
#include<set>

using namespace std;

int main(){
	int T, step, curCount, nextCount;
	queue<string> q;
	set<string> st;
	char buf[6];
	string s, res, ns;
	cin>>T;

	while(T--){
		while(!q.empty())
			q.pop();

		st.erase(st.begin(), st.end());

		cin >> s >> res;
		q.push(s);
		st.insert(s);

		step = 0;
		curCount = 1;
		nextCount = 0;
		while(1){
			s = q.front();
			q.pop();
			if(s.compare(res) == 0)
				break;

			for(int i=0; i<4; i++){
				ns = s;
				if(ns[i] == '9')
					ns[i] = '1';
				else
					ns[i]++;

				if(st.find(ns) == st.end()){
					st.insert(ns);
					q.push(ns);
					nextCount++;
				}

				ns = s;
				if(ns[i] == '1')
					ns[i] = '9';
				else
					ns[i]--;
				if(st.find(ns) == st.end()){
					st.insert(ns);
					q.push(ns);
					nextCount++;
				}
			}

			char tmp;
			for(int i=0; i<3; i++){
				ns = s;
				tmp = ns[i];
				ns[i] = ns[i+1];
				ns[i+1] = tmp;
				if(st.find(ns) == st.end()){
					st.insert(ns);
					q.push(ns);
					nextCount++;
				}
			}

			curCount--;
			if(curCount == 0){
				step++;
				curCount = nextCount;
				nextCount = 0;
			}
		}
		cout << step << endl;
	}
	return 0;
}
