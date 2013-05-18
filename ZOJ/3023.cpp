#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, m, tmp, sumA, sumB, hasSol, sa, sb, st, ed, mid;
	vector<int> a, b;

	while(cin>>n>>m && (n+m)){
		a.erase(a.begin(), a.end());
		b.erase(b.begin(), b.end());

		for(int i=0; i<n; i++){
			cin>>tmp;
			a.push_back(tmp);
		}

		for(int i=0; i<m; i++){
			cin>>tmp;
			b.push_back(tmp);
		}

		sumA = 0;
		sumB = 0;

		for(int i=0; i<n; i++)
			sumA += a[i];
		for(int i=0; i<m; i++)
			sumB += b[i];

		tmp = sumA - sumB;
		if(tmp & 1){
			cout<<-1<<endl;
			continue;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		hasSol = 0;

		for(int i=0; i<n; i++){
			sa = a[i];
			sb = a[i] - tmp/2;

			st = 0;
			ed = m-1;
			while(st <= ed){
				mid = (st+ed)>>1;
				if(b[mid] == sb){
					hasSol = 1;
					break;
				}
				else if(b[mid]>sb){
					ed = mid-1;
				}
				else{
					st = mid+1;
				}
			}

			if(hasSol){
				cout<< sa << ' '<<  sb << endl;
				break;
			}
		}
		if(!hasSol)
			cout << -1 << endl;
	}
	return 0;
}
