#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
	int T, curMin, minBid, U, M, isFirst = 1, nCase = 1, bid;
	map<int, string> mName;
	map<int, int> mTime;
	string s;

	cin >> T;
	while(T--){
		if(!isFirst)
			cout<<endl;
		else
			isFirst = 0;

		mName.erase(mName.begin(), mName.end());
		mTime.erase(mTime.begin(), mTime.end());

		cin >> U >> M;

		for(int i=0; i<M; i++){
			cin >> s >> bid;
			if(mTime.find(bid) == mTime.end()){
				mName[bid] = s;
				mTime[bid] = 1;
			}
			else
				mTime[bid]++;
		}

		minBid = M;
		curMin = bid;
		for(map<int, int>::iterator it=mTime.begin(); it!=mTime.end(); it++){
			if(it->second < minBid){
				minBid = it->second;
				curMin = it->first;
			}
		}

		cout << "Case " << nCase << ":\n";
		cout << "The winner is " << mName[curMin] << "." << endl;
		cout << "The price is " << curMin << "." << endl;
		nCase++;
	}
	return 0;
}
