#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARDS 52

struct card
{
	const char *face;
	//const char *suit;
};

typedef struct card Card;


void play(Card * const wDeck, int boilingPoint);

int main(void)
{
	int p, d=0,b=1,a;
	const char *face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	// const char *suit[] = { "紅心", "菱形", "方塊", "梅花" };

	Card deck[CARDS];
	srand(time(NULL));
	fillDeck(deck, face);
	shuffle(deck);
	play(deck, 21); /* play */
	system("pause");
}





void play(Card * const wDeck, int boilingPoint)
{
	int cnt = 4, aWantToContinue = 1, bWantToContinue = 1, aGrade = getGrade(wDeck, 0) + getGrade(wDeck, 1), bGrade = 0;
	printf("玩家A底牌為:%s %s\n",wDeck[0],wDeck[1]);
	printf("(A)目前點數%d\n", aGrade);
	while (cnt < CARDS && (aWantToContinue == 1 || bWantToContinue == 1))
	{
		printf("請問是否要抽牌呢?要的話請輸入1,部要的話請輸入0.\n");
		scanf("%d", &aWantToContinue);
		if (aWantToContinue == 1)
		{//a要繼續 
			printf("您(A)抽到%s\n", wDeck[cnt].face);

			aGrade = aGrade + getGrade(wDeck, cnt);
			cnt = cnt + 1;
			
		}
		if (aGrade>21)
		{
			printf("玩家A的點數:%d  爆掉了-->玩家B WIN!!!",aGrade);
			return 0;
		}
		
		if (aWantToContinue == 0)
			break;
	printf("(A)目前點數%d\n", aGrade);
	}
	


}