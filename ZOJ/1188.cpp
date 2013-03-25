#include<cstdio>

class binaryIndexedTree{
private:
	int *array;
	int maxSize;
public:
	binaryIndexedTree(int N):maxSize(N){
		array = new int[maxSize];
		clear();
	}

	~binaryIndexedTree(){
		delete[] array;
	}

	void clear(){
		for(int i=0; i<maxSize; i++)
			array[i] = 0;
	}

	void update(int x, int value){
		while(x < maxSize){
			array[x] += value;
			x += x&-x;
		}
	}

	int read(int x){
		int result = 0;
		while(x > 0){
			result += array[x];
			x -= x&-x;
		}
		return result;
	}

	int readOne(int x){
		if(x%2 == 1)
			return array[x];

		int sum=array[x], z=x-x&-x;
		x--;
		while(x != z){
			sum -= array[x];
			x -= x&-x;
		}
		return sum;
	}
};

class record{
public:
	char *str;
	int v;

	record(){
		str = new char[52];
		v = 0;
	}

	~record(){
		delete[] str;
	}

	void getInvertedNumber(binaryIndexedTree *t){
		t->clear();
		v = 0;
		int p=0, idx;
		while(str[p] != '\n'){
			//printf("%c", str[p]);
			idx = int(str[p]-'A'+1);
			t->update(idx, 1);
			v += p+1-t->read(idx);
			p++;
		}
	}
};

void merge(int **ra, int **rb, int st, int mid, int ed){
	int pa = st, pb = mid, p = st;
	while(pa < mid && pb <= ed){
		if(ra[pa][0] <= ra[pb][0]){
			rb[p][0] = ra[pa][0];
			rb[p++][1] = ra[pa++][1];
		}
		else{
			rb[p][0] = ra[pb][0];
			rb[p++][1] = ra[pb++][1];
		}
	}

	while(pa < mid){
		rb[p][0] = ra[pa][0];
		rb[p++][1] = ra[pa++][1];
	}

	while(pb <= ed){
		rb[p][0] = ra[pb][0];
		rb[p++][1] = ra[pb++][1];
	}
}

void mergeSort(int **idx1, int **idx2, int st, int ed){
	if(st >= ed)
		return;
	int mid = (st+ed)>>1;
	mergeSort(idx2, idx1, st, mid);
	mergeSort(idx2, idx1, mid+1, ed);
	merge(idx2, idx1, st, mid+1, ed);
}

int main(){
	int N, n, m;
	scanf("%d", &N);
	binaryIndexedTree *t = new binaryIndexedTree(27);

	record **r = new record*[102];
	int **idx1, **idx2;
	idx1 = new int*[102];
	idx2 = new int*[102];
	for(int i=0; i<102; i++){
		r[i] = new record();
		idx1[i] = new int[2];
		idx2[i] = new int[2];
	}
	while(N > 0){
		scanf("%d %d\n", &n, &m);
		for(int i=0; i<m; i++){
			fgets(r[i]->str, sizeof(char)*52, stdin);
			r[i]->getInvertedNumber(t);
			idx1[i][0] = r[i]->v;
			idx1[i][1] = i;
			idx2[i][0] = r[i]->v;
			idx2[i][1] = i;
		}

		if(m > 1){
			mergeSort(idx1, idx2, 0, m-1);
		}
		for(int i=0; i<m; i++)
			printf("%s", r[idx1[i][1]]->str);
		printf("\n");
		N--;
	}

	for(int i=0; i<102; i++){
		delete[] idx1[i];
		delete[] idx2[i];
		delete r[i];
	}
	delete[] idx1;
	delete[] idx2;
	delete[] r;
	delete t;
	return 0;
}
