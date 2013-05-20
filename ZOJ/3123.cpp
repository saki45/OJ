#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int T, N, S, nums[100001], sum[100001], minLength;
	cin>>T;
	while(T--){
		cin>>N>>S;
		sum[0] = 0;
		nums[0] = 0;
		for(int i=1; i<=N; i++){
			cin>>nums[i];
			sum[i] = sum[i-1]+nums[i];
		}

		if(sum[N] < S){
			cout<<0<<endl;
			continue;
		}
		else if(sum[N] == S){
			cout<<N<<endl;
			continue;
		}
		
		vector<int> v(sum+1, sum+N+1);
		vector<int>::iterator it, itst = v.begin();
		minLength = N;

		for(int i=1; i<=N; i++){
			it = lower_bound(itst, v.end(), S+sum[i-1]);
			if(it == v.end())
				break;
			minLength = min(minLength, it-itst+1);
			itst++;
		}
		cout<<minLength<<endl;
	}
	return 0;
}
