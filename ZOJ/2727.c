#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record{
	char name[85];
	int year;
	int price;
};

void printRecord(struct record *r){
	printf("%s %d %d\n", r->name, r->year, r->price);
}

int cmpName(const void *p1, const void *p2){
	const struct record *pp1 = p1;
	const struct record *pp2 = p2;

	int cmp = strcmp(pp1->name, pp2->name);

	if(cmp != 0)
		return cmp;
	else{
		if(pp1->year != pp2->year)
			return pp1->year - pp2->year;
		else{
			return pp1->price - pp2->price;
		}
	}
	return 0;
}

int cmpYear(const void *p1, const void *p2){
	const struct record *pp1 = p1;
	const struct record *pp2 = p2;

	if(pp1->year != pp2->year)
		return pp1->year - pp2->year;
	else{
		int cmp = strcmp(pp1->name, pp2->name);
		if(cmp != 0)
			return cmp;
		else{
			return pp1->price - pp2->price;
		}
	}
	return 0;
}
int cmpPrice(const void *p1, const void *p2){
	const struct record *pp1 = p1;
	const struct record *pp2 = p2;

	if(pp1->price != pp2->price)
		return pp1->price - pp2->price;
	else{
		int cmp = strcmp(pp1->name, pp2->name);
		if(cmp != 0)
			return cmp;
		else{
			return pp1->year - pp2->year;
		}
	}
	return 0;
}

int main(){
	int N, p;
	scanf("%d", &N);
	getchar();
	struct record r[102];
	char buf[100], *str, *tok;
	while(N != 0){
		p = 0;
		while(p < N){
			fgets(buf, sizeof(buf), stdin);
			str = buf;
			tok = strtok(str, " \n");
			strcpy(r[p].name, tok);
			tok = strtok(NULL, " \n");
			r[p].year = atoi(tok);
			tok = strtok(NULL, " \n");
			r[p].price = atoi(tok);

			p++;
		}
		fgets(buf, sizeof(buf), stdin);
		if(!strcmp(buf, "Name\n"))
			qsort(r, N, sizeof(struct record), cmpName);
		else if(!strcmp(buf, "Year\n"))
			qsort(r, N, sizeof(struct record), cmpYear);
		else
			qsort(r, N, sizeof(struct record), cmpPrice);

		for(p=0; p<N; p++)
			printRecord(&r[p]);

		scanf("%d", &N);
		getchar();
		if(N)
			printf("\n");
	}

	return 0;
}
