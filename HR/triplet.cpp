#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

template<typename T>
class binaryIndexedTree{
private:
	int maxSize;
	T *tree;
public:
	binaryIndexedTree(int N):maxSize(N){
		tree = (T*)calloc(N+1, sizeof(T));
	}

	~binaryIndexedTree(){
		free(tree);
	}

	// increase [index] by value
	void update(int index, int value){
		if(index <= 0 || index > maxSize)
			return;

		while(index <= maxSize){
			tree[index] += value;
			index += index & -index;
		}
	}

	// read the summation of values in tree[1..index]
	T read(int index){
		if(index <= 0 || index > maxSize)
			return 0;

		T sum = 0;
		while(index > 0){
			sum += tree[index];
			index -= index & -index;
		}
		return sum;
	}

	T readSingle(int index){
		if(index <=0 || index > maxSize)
			return 0;

		if(index % 2 == 1)
			return tree[index];

		T sum = tree[index];
		int z = index - (index & -index);
		index --;
		while(z != index){
			sum -= tree[index];
			index -= index & -index;
		}
		return sum;
	}

	void printElement(){
		for(int i=1; i<=maxSize; i++){
			printf("%d %d %d %d\n", i, tree[i], readSingle(i), read(i));
		}
	}
};

int main(){
	int N;
	scanf("%d", &N);
	unsigned int *data = new unsigned int[N];
	unsigned int *dataTmp = new unsigned int[N];
	for(int i=0; i<N-1; i++){
		scanf("%u ", &data[i]);
		dataTmp[i] = data[i];
	}
	scanf("%u", &data[N-1]);
	dataTmp[N-1] = data[N-1];

	std::sort(dataTmp, dataTmp+N);

	int count = 1, cur = dataTmp[0];
	for(int i=1; i<N; i++){
		if(dataTmp[i] != cur){
			count ++;
			cur = dataTmp[i];
		}
	}

	map<unsigned int, unsigned int> mp;
	map<unsigned int, unsigned int>::iterator it;

	count = 1;
	cur = dataTmp[0];
	mp[cur] = 1;

	for(int i=1; i<N; i++){
		if(dataTmp[i] != cur){
			count ++;
			cur = dataTmp[i];
			mp[cur] = count;
		}
	}

	binaryIndexedTree<int> *bt1 = new binaryIndexedTree<int>(count);
	binaryIndexedTree<int> *bt2 = new binaryIndexedTree<int>(count);

	int *a1 = (int*)calloc(count+1, sizeof(int));
	int *a2 = (int*)calloc(count+1, sizeof(int));
	int *a3 = (int*)calloc(count+1, sizeof(int));

	for(int i=0; i<N; i++){
		int idx = mp[data[i]];

		if(a1[idx] == 0){
			bt1->update(idx, 1);
			a1[idx] = 1;
		}

		if(idx == 1)
			continue;

		int cum1 = bt1->read(idx-1);
		if(a2[idx] < cum1){
			bt2->update(idx, cum1 - a2[idx]);
			a2[idx] = cum1;
		}

		a3[idx] = bt2->read(idx-1);
	}

	long long sum = 0;
	for(int i=1; i<=count; i++)
		sum += a3[i];

	printf("%Ld\n", sum);

	delete bt1;
	delete bt2;
	delete[] data;
	delete[] dataTmp;
	free(a1);
	free(a2);
	free(a3);
}	
