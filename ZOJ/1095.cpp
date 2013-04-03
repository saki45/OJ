#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

unsigned match(unsigned int tTree[]){
	tTree[4] = min(tTree[0], tTree[1]);
	tTree[5] = min(tTree[2], tTree[3]);
	tTree[6] = min(tTree[4], tTree[5]);

	return tTree[6];
}

int main(){
	unsigned int arr[5843], tTree[7], tmp;
	for(int i=0; i<7; i++)
		tTree[i] = 999;
	int nArr;
	queue<unsigned int> q2, q3, q5, q7;
	arr[1] = 1;
	nArr = 2;
	q2.push(2);
	q3.push(3);
	q5.push(5);
	q7.push(7);
	tTree[0] = 2;
	tTree[1] = 3;
	tTree[2] = 5;
	tTree[3] = 7;

	while(nArr < 5843){
		tmp = match(tTree);
		arr[nArr++] = tmp;
		if(tmp%7 == 0){
			q7.pop();
			q7.push(tmp*7);
			tTree[3] = q7.front();
		}
		else if(tmp % 5 == 0){
			q5.pop();
			q5.push(tmp*5);
			q7.push(tmp*7);
			tTree[2] = q5.front();
		}
		else if(tmp % 3 == 0){
			q3.pop();
			q3.push(tmp*3);
			q5.push(tmp*5);
			q7.push(tmp*7);
			tTree[1] = q3.front();
		}
		else{
			q2.pop();
			q2.push(tmp*2);
			q3.push(tmp*3);
			q5.push(tmp*5);
			q7.push(tmp*7);
			tTree[0] = q2.front();
		}
	}
	int N;
	scanf("%d", &N);
	while(N > 0){
		if(N % 100 == 11 || N % 100 == 12 || N % 100 == 13)
			printf("The %dth humble number is %u.\n", N, arr[N]);
		else if(N%10 == 1)
			printf("The %dst humble number is %u.\n", N, arr[N]);
		else if(N%10 == 2)
			printf("The %dnd humble number is %u.\n", N, arr[N]);
		else if(N%10 == 3)
			printf("The %drd humble number is %u.\n", N, arr[N]);
		else
			printf("The %dth humble number is %u.\n", N, arr[N]);

		scanf("%d", &N);
	}
	return 0;
}
