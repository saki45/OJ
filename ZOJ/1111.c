#include<stdio.h>
#include<string.h>

char* processCards(int cards[][4], int cardsSum[], char *str, int hash[]){
	memset(cards, 0, sizeof(int)*60);
	memset(cardsSum, 0, sizeof(int)*15);

	int i, num, color;
	for(i=0; i<5; i++){
		num = hash[(*str)];
		str++;
		color = hash[(*str)];
		str += 2;
		cards[num][color]++;
		cards[0][color]++;
		cardsSum[num]++;
	}
	return str;
}

int getRank(int cards[][4], int cardsSum[]){
	int i, hasThree=0, hasTwo=0, isFlush=0, isStraight=0, count=0;

	for(i=2; i<15; i++){
		if(cardsSum[i] == 4)
			return 7;
		if(cardsSum[i] == 3)
			hasThree = 1;
		if(cardsSum[i] == 2)
			hasTwo++;
		if(cardsSum[i-1]==1 && cardsSum[i] == 1)
			count ++;
		if(cardsSum[i-1]==0 && cardsSum[i]==1 && count == 0)
			count ++;
	}

	if(hasThree && hasTwo)
		return 6;
	else if(hasThree)
		return 3;
	else if(hasTwo == 2)
		return 2;
	else if(hasTwo)
		return 1;

	if(count == 5)
		isStraight = 1;
	for(i=0; i<4; i++)
		if(cards[0][i] == 5)
			isFlush = 1;

	if(isStraight && isFlush)
		return 8;
	else if(isStraight)
		return 4;
	else if (isFlush)
		return 5;

	return 0;
}

int getMax(int cardsSum[], int value, int st){
	int i;
	for(i=st; i>=2; i--)
		if(cardsSum[i] == value)
			return i;
	return 0;
}

int compareSameRank(int bCardsSum[], int wCardsSum[], int rank){
	int res=0, bMax=0, wMax=0, i;
	switch(rank){
		case 0:
		case 5:
			bMax = 15;
			wMax = 15;
			while(bMax == wMax && bMax>0){
				bMax = getMax(bCardsSum, 1, bMax-1);
				wMax = getMax(wCardsSum, 1, wMax-1);
			}
			break;
		case 4:
		case 8:
			bMax = getMax(bCardsSum, 1, 14);
			wMax = getMax(wCardsSum, 1, 14);
			break;
		case 1:
			bMax = getMax(bCardsSum, 2, 14);
			wMax = getMax(wCardsSum, 2, 14);
			if(bMax == wMax){
				bMax = 15;
				wMax = 15;
				while(bMax == wMax && bMax>0){
					bMax = getMax(bCardsSum, 1, bMax-1);
					wMax = getMax(wCardsSum, 1, wMax-1);
				}
			}
			break;
		case 2:
			bMax = getMax(bCardsSum, 2, 14);
			wMax = getMax(wCardsSum, 2, 14);
			if(bMax == wMax){
				bMax = getMax(bCardsSum, 2, bMax-1);
				wMax = getMax(wCardsSum, 2, wMax-1);
			}
			if(bMax == wMax){
				bMax = getMax(bCardsSum, 1, 14);
				wMax = getMax(wCardsSum, 1, 14);
			}
			break;
		case 3:
		case 6:
			bMax = getMax(bCardsSum, 3, 14);
			wMax = getMax(wCardsSum, 3, 14);
			break;
		case 7:
			bMax = getMax(bCardsSum, 4, 14);
			wMax = getMax(wCardsSum, 4, 14);
			break;
	}
	return bMax - wMax;
}

int main(){
	int bCards[15][4], bCardsSum[15], wCards[15][4], wCardsSum[15], i, hash[256], bRank, wRank;
	int bWin, wWin, cmpResult;
	char buf[50], *str;

	memset(hash, 0, sizeof(hash));
	for(i='2'; i<='9'; i++){
		hash[i] = i-'2'+2;
	}
	hash['T'] = 10;
	hash['J'] = 11;
	hash['Q'] = 12;
	hash['K'] = 13;
	hash['A'] = 14;

	hash['C'] = 0;
	hash['D'] = 1;
	hash['H'] = 2;
	hash['S'] = 3;

	while(fgets(buf, sizeof(buf), stdin) != NULL){
		bWin = 0;
		wWin = 0;

		str = buf;
		str = processCards(bCards, bCardsSum, str, hash);
		processCards(wCards, wCardsSum, str, hash);

		bRank = getRank(bCards, bCardsSum);
		wRank = getRank(wCards, wCardsSum);

		if(bRank>wRank)
			bWin = 1;
		else if(wRank>bRank)
			wWin = 1;
		else{
			cmpResult = compareSameRank(bCardsSum, wCardsSum, bRank);
			if(cmpResult > 0)
				bWin = 1;
			else if(cmpResult < 0)
				wWin = 1;
		}

		if(bWin)
			printf("Black wins.\n");
		else if(wWin)
			printf("White wins.\n");
		else
			printf("Tie.\n");
	}
	return 0;
}
