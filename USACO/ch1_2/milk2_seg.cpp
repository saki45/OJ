/*
ID: saki451
PROG: milk2
LANG: C++
*/

#include<cstdio>
#include<map>

#define MAX 30000

using namespace std;

class segmentTreeNode{
public:
	int st, ed, value;

	segmentTreeNode(int start, int end):st(start), ed(end){
		value = 0;
	}
};

class segmentTree{
public:
	segmentTreeNode **pArr;
	int low, high;

	segmentTree(int st, int ed):low(st), high(ed){
		if(low >= high){
			head = NULL;
			return;
		}
		pArr = new segmentTreeNode*[MAX];
		for(int i=0; i<MAX; i++)
			pArr[i] = new segmentTreeNode(0, 0);
	}

	~segmentTree(){
		for(int i=0; i<MAX; i++)
			delete pArr[i];
		delete[] pArr;
	}

	int insertInterval(int i, int st, int ed){
		if(pArr[i]->st == pArr[i]->
	}

	int query(int st, int ed){

	}

private:

};
