#include<stdio.h>
#include<string.h>

int main(){
	int p[6][2], corres[6], i, j, ncorres, tmp, edges[6], edgecount[6], pe, pi;
	while(scanf("%d%d", &p[0][0], &p[0][1]) != EOF){
		for(i=1; i<6; i++)
			scanf("%d%d", &p[i][0], &p[i][1]);

		for(i=0; i<6; i++){
			if(p[i][0] > p[i][1]){
				tmp = p[i][0];
				p[i][0] = p[i][1];
				p[i][1] = tmp;
			}
		}

		memset(corres, 0, sizeof(corres));
		ncorres = 0;
		for(i=0; i<5; i++){
			if(!corres[i]){
				for(j=i+1; j<6; j++){
					if(p[i][0] == p[j][0] && p[i][1] == p[j][1]){
						corres[i] = j+1;
						corres[j] = i+1;
						ncorres++;
						break;
					}
				}
				if(j==6){
					ncorres = 0;
					break;
				}
			}
		}

		if(ncorres < 3){
			printf("IMPOSSIBLE\n");
			continue;
		}

		memset(edges, 0, sizeof(edges));
		memset(edgecount, 0, sizeof(edgecount));

		pe = 0;
		edges[0] = p[0][0];
		edgecount[0]++;
		if(p[0][1] == p[0][0])
			edgecount[0]++;
		else{
			edges[1] = p[0][1];
			edgecount[1]++;
			pe = 1;
		}
		corres[corres[0]-1] = 0;
		for(i=1; i<6; i++){
			if(corres[i]){
				for(j=0; j<2; j++){
					for(pi=0; pi<=pe; pi++){
						if(p[i][j] == edges[pi]){
							edgecount[pi]++;
							break;
						}
					}
					if(pi > pe){
						pe++;
						edges[pe] = p[i][j];
						edgecount[pe]++;
					}
				}
				corres[corres[i]-1] = 0;
			}	
		}

		if(pe >= 3)
			printf("IMPOSSIBLE\n");
		else if((pe==0&&edgecount[0]==6) || (pe==1&&((edgecount[0]==4&&edgecount[1]==2)||(edgecount[0]==2&&edgecount[1]==4))) || (pe==2&&edgecount[0]==2&&edgecount[1]==2&&edgecount[2]==2))
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
