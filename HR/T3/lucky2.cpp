#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>

#define SUMMAP_SIZE 100
#define DIFFMAP_SIZE 100

using namespace std;

void getPrimeMap(int *primeMap, int N){
	primeMap[0] = 0;
	primeMap[1] = 0;
	int i;

	for(i=2; i<N; i++)
		primeMap[i] = 1;

	for(i=2; i<N; i++){
		if(primeMap[i]){
			int j=i*2;
			while(j<N){
				primeMap[j] = 0;
				j += i;
			}
		}
	}
}

void computeG(long long ***g, long long ***h,  int **st, int **ed){
	for(int i=0; i<19; i++){
		for(int j=0; j<9*i+1; j++){
			for(int k=0; k<81*i+1; k++){
				g[i][j][k] = 0;
				h[18-i][j][k] = 0;
			}
		}
	}
	for(int i=0; i<19; i++){
		for(int j=0; j<9*i+1; j++){
			st[i][j] = 9*9*i+1;
			ed[i][j] = -1;
		}
	}

	for(int j=0; j<=9; j++){
		g[1][j][j*j] = 1;
		st[1][j] = j*j;
		ed[1][j] = j*j;
	}

	for(int i=2; i<19; i++){
		for(int j=0; j<9*(i-1)+1; j++){
			for(int k=st[i-1][j]; k<=ed[i-1][j]; k++){
				if(g[i-1][j][k] != 0){
					for(int l=0; l<=9; l++){
						g[i][j+l][k+l*l] += g[i-1][j][k];
						if(st[i][j+l] > k+l*l)
							st[i][j+l] = k+l*l;
						if(ed[i][j+l] < k+l*l)
							ed[i][j+l] = k+l*l;
					}
				}
			}
		}
	}
}

long long getH(long long ***g, long long ***h, int **st, int **ed, int i, int A, int B, int *primeMap){

	//printf("st i:%d A:%d B:%d h:%Ld\n", i, A, B, h[i][A][B]);
	if(h[i][A][B] > 0){
		return h[i][A][B];
	}

	if(i == 0){
		if(primeMap[A] && primeMap[B])
			h[i][A][B] = 1;
		return h[i][A][B];
	}

	int aMax = 9*i;
	int bMax = 81*i;
	for(int aa=0; aa<=aMax; aa++){
		if(primeMap[A+aa]){
			for(int bb=st[i][aa]; bb<=bMax && bb<=ed[i][aa] && bb<=aa*aa; bb++){
				//printf("%d %d %d:%d %d\n", i, aa, bb, st[i][aa], ed[i][aa]);
				if(primeMap[B+bb]){
					//printf("%d %d %d:%d %d\n", i, aa, bb, st[i][aa], ed[i][aa]);
					h[i][A][B] += g[i][aa][bb];
				}
			}
		}
	}

	return h[i][A][B];
}

long long getNumber(string str, long long ***g, long long ***h, int **st, int **ed, int *primeMap){
	long long result = 0L;
	int N = str.length()-1;
	int A=0, B=0;
	for(int i=N; i>=0; i--){
		int num = int(str[N-i] - '0');
		int t1 = i;
		for(int j=0; j<num; j++){
			long long res = getH(g, h, st, ed, t1, A+j, B+j*j, primeMap);
			//result += getH(g, h, st, ed, t1, A+j, B+j*j, primeMap);
			//printf("ti:%d num:%d A:%d B:%d j:%d res:%Ld\n", t1, num, A, B, j, res);
			result += res;
		}
		A += num;
		B += num*num;
	}
	if(primeMap[A] && primeMap[B])
		result ++;
	//printf("%Ld\n", result);
	return result;
}


long long isLucky(string a, int *primeMap){
	int A=0, B=0, N = a.length(), digit;
	for(int i=0; i<N; i++){
		digit = int(a[i]-'0');
		A += digit;
		B += digit*digit;
	}
	return primeMap[A]*primeMap[B];
}


int main(){
	int T;
	scanf("%d\n", &T);
	int *primeMap = (int*)malloc(1500*sizeof(int));
	getPrimeMap(primeMap, 1500);

	long long ***g, ***h;
	int **st, **ed;
	st = new int*[19];
	ed = new int*[19];
	for(int i=0; i<19; i++){
		st[i] = new int[9*i+1];
		ed[i] = new int[9*i+1];
	}

	g = new long long**[19];
	h = new long long**[19];
	for(int i=0;i<19; i++){
		g[i] = new long long*[9*i+1];
		h[18-i] = new long long*[9*i+1];
	}
	for(int i=0;i<19; i++){
		for(int j=0; j<9*i+1;j++){
			g[i][j] = new long long[81*i+1];
			h[18-i][j] = new long long[81*i+1];
		}
	}
	computeG(g, h, st, ed);

	string a, b;
	char buf[100];
	char *input = buf, *token;
	long long resultA, resultB, isLuckyA;
		
	while(T>0){
		fgets(buf, sizeof(buf), stdin);
		token = strtok(input, " ");
		a = token;
		token = strtok(NULL, " \n");
		b = token;
		//printf("%s\n", a.c_str());
		//printf("%s\n", b.c_str());

		resultA = getNumber(a, g, h, st, ed, primeMap);
		resultB = getNumber(b, g, h, st, ed, primeMap);
		isLuckyA = isLucky(a, primeMap);

		printf("%Ld\n", resultB-resultA+isLuckyA);
		T--;
	}

	for(int i=0; i<19; i++){
		delete[] st[i];
		delete[] ed[i];
	}
	delete[] st;
	delete[] ed;

	for(int i=0; i<19; i++){
		for(int j=0; j<9*i+1; j++){
			delete[] g[i][j];
			delete[] h[18-i][j];
		}
	}
	for(int i=0; i<19; i++){
		delete[] g[i];
		delete[] h[18-i];
	}
	delete[] g;
	delete[] h;
}
