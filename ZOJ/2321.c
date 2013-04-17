#include<stdio.h>

int canDoWR(double spd, double w, double s){
	return (spd <=4.5 && w>=150 && s>=200);
}

int canDoLM(double spd, double w, double s){
	return (spd<=6.0 && w>=300 && s>=500);
}

int canDoQB(double spd, double w, double s){
	return (spd<=5.0 && w>=200 &&s>=300);
}

int main(){
	double speed, w, s;
	int isMatched;
	while(scanf("%lf%lf%lf", &speed, &w, &s) && (speed+w+s)){
		isMatched = 0;
		if(canDoWR(speed, w, s)){
			isMatched = 1;
			printf("Wide Receiver");
		}
		if(canDoLM(speed, w, s)){
			if(isMatched)
				printf(" ");
			isMatched = 1;
			printf("Lineman");
		}
		if(canDoQB(speed, w, s)){
			if(isMatched)
				printf(" ");
			isMatched = 1;
			printf("Quarterback");
		}
		if(isMatched)
			printf("\n");
		else
			printf("No positions\n");
	}
	return 0;
}
