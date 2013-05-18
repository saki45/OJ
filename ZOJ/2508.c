#include<stdio.h>

struct window{
	int x1, x2, y1, y2, isMax, prev, next;
};

int main(){
	struct window w[6];
	int M, N, H, Wmax, Hmax, head, i, cx, cy, px, py, isFirst, isTitle, isDup, idx;
	while(scanf("%d%d%d%d", &N, &H, &Wmax, &Hmax) != EOF){
		for(i=0; i<N; i++){
			scanf("%d%d%d%d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
			w[i].isMax = 0;
			w[i].prev = i+1;
			w[i].next = i-1;
		}
		head = N-1;

		scanf("%d", &M);
		isFirst = 1;
		idx = head;
		while(M--){
			scanf("%d%d", &cx, &cy);
			isTitle = 0;
			if(w[head].isMax && cy>=Hmax-H){
				isTitle = 1;
				idx = head;
			}
			else if(w[head].x1 <= cx && w[head].x2 >= cx && w[head].y1>= cy && w[head].y1-H <= cy){
				isTitle = 1;
				idx = head;
			}
			else{
				idx = -1;
				for(i=head; i!=-1; i=w[i].next){
					if(w[i].isMax){
						idx = i;
						break;
					}
					if(w[i].x1 <= cx && w[i].x2 >= cx && w[i].y2+H >= cy && w[i].y2 <= cy){
						idx = i;
						isTitle = 1;
						break;
					}
					if(w[i].x1<=cx && w[i].x2>=cx && w[i].y1>=cy && w[i].y2<=cy){
						idx = i;
						break;
					}
				}
				if(idx!=-1 && idx != head){
					w[w[idx].prev].next = w[idx].next;
					if(w[idx].next != -1)
						w[w[idx].next].prev = w[idx].prev;
					w[head].prev = idx;
					w[idx].prev = N;
					w[idx].next = head;
					head = idx;
				}
			}
			if(isFirst){
				isFirst = 0;
				printf("%d", idx);
			}
			else{
				isDup = 0;
				if(cx==px && cy==py){
					isDup = 1;
				}
				if(isDup){
					if(isTitle){
						w[head].isMax = 1 - w[head].isMax;
						idx = head;
					}
				}
				printf(" %d", idx);
			}
			px = cx;
			py = cy;
		}
		printf("\n");
	}
	return 0;
}
