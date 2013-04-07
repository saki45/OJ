#include<iostream>
#include<string>

using namespace std;

int main(){
	string str[15];
	int n, st, count=1;
	while(cin>>n && n>0){
		cout<<"SET "<<count<<endl;
		count++;
		for(int i=0; i<n; i++)
			cin>>str[i];
		for(int i=0; i<n; i+=2){
			cout<<str[i]<<endl;
		}
		if(n&1)
			st = n-2;
		else
			st = n-1;

		for(int i=st; i>=0; i-=2)
			cout<<str[i]<<endl;
	}
	return 0;
}
