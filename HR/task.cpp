#include<map>
#include<iostream>

using namespace std;

int main() {
	int T;
	cin>>T;

	map<int, long> mp;
	map<int, long>::iterator it;

	int Di, Mi;
	cin >> Di >> Mi;
	long maxDiff = Mi - Di;
	int maxDD = Di;
	mp[Di] = Mi;
	T--;
	if(maxDiff < 0){
		cout<<0<<endl;
	}
	else{
		cout<<maxDiff<<endl;
	}

	while(T>0){
		cin>>Di>>Mi;

		long curDiff = 0, curTotal = 0;
		int thisD = 0;

		if(Di <= maxDD){
			if(maxDiff < 0){	
				it = mp.find(Di);
				int prev;
				if(it == mp.end()){
					prev = 0;
					mp[Di] = Mi;
				}
				else{
					prev = mp[Di];
				}

				if(Mi+prev-Di > maxDiff+Mi){
				
					maxDD = Di;
					maxDiff = Mi + prev - Di;
					mp[Di] = Di + maxDiff;
				}
				else{
					maxDiff += Mi;
				}
			}
			else{
				maxDiff += Mi;
			}
		}
		else{
			it = mp.find(Di);
			if(it != mp.end()){
				mp[Di] += Mi;
			}
			else{
				mp[Di] = Mi;
			}

			it = mp.find(maxDD);
			curTotal = maxDD + maxDiff;
			it ++;
			while(it != mp.end()){
				thisD = (*it).first;
				curTotal += (*it).second;
				//cout<<thisD<<' '<<curTotal<<endl;
				curDiff = curTotal - thisD;
				if(curDiff >= maxDiff){
					maxDiff = curDiff;
					maxDD = thisD;
					//while((*(mp.begin())).first < maxDD)
					//	mp.erase((*(mp.begin())).first);
				}
				it++;
			}
		}

		if(maxDiff < 0)
			cout<< 0 <<endl;
		else
			cout<<maxDiff<<endl;
	
		T--;
	}
}
