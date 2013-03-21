/*
 ID:saki451
 LANG:C++
 TASK:gift1
 PROG gift1
 */

#include<string>
#include<map>
#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	FILE *fin, *fout;
	fin = fopen("gift1.in", "r");
	fout = fopen("gift1.out", "w");

	int NP;
	fscanf(fin, "%d", &NP);

	map<string, int> recv, pay;
	string *names = new string[NP];

	char *tmpStr;

	for(int i=0; i<NP; i++){
		fscanf(fin, "%s", tmpStr);
		names[i] = string(tmpStr);
	}

	for(int i=0; i<NP; i++){
		recv[names[i]] = 0;
		pay[names[i]] = 0;
	}

	int sum, nFriend, eachAmount;

	for(int i=0; i<NP; i++){
		fscanf(fin, "%s %d %d", tmpStr, &sum, &nFriend);
		string thisName(tmpStr);
		if(nFriend > 0){
			eachAmount = sum / nFriend;
			for(int j=0; j<nFriend; j++){
				fscanf(fin, "%s", tmpStr);
				string tmpName(tmpStr);
				recv[tmpName] += eachAmount;
			}
			pay[thisName] = eachAmount*nFriend;
		}
	}

	for(int i=0; i<NP; i++){
		fprintf(fout, "%s %d\n", names[i].c_str(), recv[names[i]]-pay[names[i]]);
		printf("%s %d\n", names[i].c_str(), recv[names[i]]-pay[names[i]]);
	}

	delete[] names;
}
