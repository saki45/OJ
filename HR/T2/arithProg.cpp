#include<cstdlib>
#include<cstdio>

#define MAX 1000003
using namespace std;

long long getMod(int base, long long exp){
	if(exp == 1)
		return base % MAX;
	if(exp % 2 == 0){
		long long tmp = getMod(base, exp/2);
		return (tmp * tmp) % MAX;
	}
	else{
		long long tmp = getMod(base, exp/2);
		tmp = (tmp * tmp) % MAX;
		return (base * tmp) % MAX;
	}
}

void factModTable(long long *fMap){
	fMap[0] = 1;
	fMap[1] = 1;
	for(int i=2; i<MAX; i++){
		fMap[i] = (fMap[i-1]*i) % MAX;
	}
}

int main(){
	int n, q;
	scanf("%d", &n);

	int *a = new int[n+1];
	int *d = new int[n+1];
	int *p = new int[n+1];

	long long *fMap = new long long[MAX];
	factModTable(fMap);

	for(int i=0; i<n; i++){
		scanf("%d %d %d",&a[i+1], &d[i+1], &p[i+1]);
	}

	scanf("%d", &q);
	while(q--){
		int ins, i, j, v;
		scanf("%d", &ins);
		if(ins == 1){
			scanf(" %d %d %d", &i, &j, &v);
			for(int st=i;st<=j;st++){
				p[st] += v;
			}

		}
		else{
			scanf(" %d %d", &i, &j);
			long long sumP = 0;
			long long sumMod = 1;
			for(int st=i; st<=j; st++){
				sumP += p[st];
			}

			if(sumP < MAX){
				for(int st=i; st<=j; st++){
					sumMod = (sumMod * getMod(d[st], p[st])) % MAX;
				}
				sumMod = (sumMod * fMap[sumP]) % MAX;
			}
			else
				sumMod = 0;
			printf("%Ld %Ld\n", sumP, sumMod);
		}
	}

	delete[] a;
	delete[] d;
	delete[] p;
	delete[] fMap;
}

