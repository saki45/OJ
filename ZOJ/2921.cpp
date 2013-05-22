#include<iostream>
#include<queue>

#define SIZE 100000

using namespace std;

struct record{
	int price, amount;

	bool operator < (const record &obj) const{
		return price < obj.price;
	}
};

int main(){
	priority_queue<record> pq;
	int T, n, x[SIZE], p[SIZE], m[SIZE], sum, tm;
	record tmp;
	cin >> T;
	while(T--){
		sum = 0;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x[i] >> p[i] >> m[i];
		}

		while(pq.size()>0)
			pq.pop();

		for(int i=n-1; i>=0; i--){
			tmp.price = p[i];
			tmp.amount = m[i];
			pq.push(tmp);

			while(x[i]>0 && pq.size()>0){
				tm = pq.top().amount;
				if(tm >= x[i]){
					sum += pq.top().price*x[i];
					tm -= x[i];
					x[i] = 0;
				}
				else{
					x[i] -= tm;
					sum += pq.top().price*tm;
					tm = 0;
				}
				if(tm == 0)
					pq.pop();
				else{
					tmp = pq.top();
					pq.pop();
					tmp.amount = tm;
					pq.push(tmp);
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
