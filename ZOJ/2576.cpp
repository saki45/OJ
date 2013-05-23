#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

using namespace std;

int nums[20], N;
vector< vector<int> > s;
vector<int> v;

void print(){
	printf("{");
	int i;
	for(i=0; i<v.size()-1; i++){
		printf("%d,", v[i]);
	}
	printf("%d}\n", v[v.size()-1]);
}

void dfs(int r, int p, int q){
	if(p == 1){
		if(r <= N){
			nums[q] = r;
			v.erase(v.begin(), v.end());
			for(int i=q; i>=0; i--)
				v.push_back(nums[i]);
			s.push_back(v);
		}
	}
	else{
		int st = min(r-p+1, nums[q-1]), ed = max(r/p, 1), i;
		for(i=st; i>=ed; i--){
			if(i <= nums[q-1] && i*p>=r){
				nums[q] = i;
				dfs(r-i, p-1, q+1);
			}
		}
	}
}

int main(){
	while(scanf("%d", &N) && N){
		memset(nums, 0, sizeof(nums));
		s.erase(s.begin(), s.end());
		int i, j;
		for(i=2*N; i>=2; i--){
			for(j=N; j>=1; j--){
				if(2*N-j >= i-1 && j*i>=2*N){
					nums[0] = j;
					dfs(2*N-j, i-1, 1);
				}
			}
		}
		sort(s.begin(), s.end());
		vector< vector<int> >::iterator it;
		for(it=s.begin(); it!=s.end(); it++){
			v = *it;
			print();	
		}
		printf("\n");
	}
	return 0;
}
