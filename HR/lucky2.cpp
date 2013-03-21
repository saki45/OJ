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

void computeG(int ***g, int **st, int **ed){
	for(int i=0; i<19; i++){
		for(int j=0; j<9*i+1; j++){
			for(int k=0; k<81*i+1; k++){
				g[i][j][k] = 0;
			}
		}
	}
	for(int i=0; i<19; i++){
		for(int j=0; j<9*i+1; j++){
			st[i][j] = 9*i+1;
			ed[i][j] = -1;
		}
	}

	for(int j=0; j<9; j++){
		g[1][j][j*j] = 1;
		st[1][j] = j;
		ed[1][j] = j;
	}

	for(int i=2; i<19; i++){
		for(int j=0; j<9*(i-1)+1; j++){
			for(int k=st[i-][j]; k<=ed[i-1][j]; k++){
				if(g[i-1][j][k] != 0)
				
}

int main(){
	int T;
	scanf("%d\n", &T);
	int *primeMap = (int*)malloc(1500*sizeof(int));
	getPrimeMap(primeMap, 1500);

	int ***g;
	int **st, **ed;
	st = new int*[19];
	ed = new int*[19];
	for(int i=0; i<19; i++){
		st[i] = new int[9*i+1];
		ed[i] = new int[9*i+1];
	}

	g = new int**[19];
	for(int i=0;i<19; i++)
		g[i] = new int*[9*i+1];
	for(int i=0;i<19; i++){
		for(int j=0; j<9*i+1;j++){
			g[i][j] = new int[81*i+1];
		}
	}
	//computeG(g, st, ed);

	
	string a, b;
	char buf[100];
	char *input = buf, *token;
		
	while(T>0){
		gets(buf);
		token = strtok(input, " ");
		a = token;
		token = strtok(NULL, " ");
		b = token;

		printf("%s\n", a.c_str());
		printf("%s\n", b.c_str());

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
		}
	}
	for(int i=0; i<19; i++){
		delete[] g[i];
	}
	delete[] g;
}
