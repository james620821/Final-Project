#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARDS 52

struct card
{
	const char *face;

};

typedef struct card Card;

void fillDeck(Card *const wDeck, const char *wFace[]);
void shuffle(Card *const wDeck);
void play(Card * const wDeck, int boilingPoint);
int getGrade(Card * const wDeck, int x);

int main(void)
{
	int p, d = 0, b = 1, a;
	const char *face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };


	Card deck[CARDS];
	srand(time(NULL));
	fillDeck(deck, face);
	shuffle(deck);
	play(deck, 21);
	system("pause");
}

void fillDeck(Card *const wDeck, const char *wFace[])
{
	int i;
	for (i = 0; i < CARDS; ++i)
	{
		wDeck[i].face = wFace[i % 13];

	}
}

void shuffle(Card *const wDeck)
{
	int i, j;
	Card temp;
	for (i = 0; i < CARDS; ++i)
	{
		j = rand() % CARDS;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}






}
int getGrade(Card * const wDeck, int x)
{
	int grade = 0, userInput = 1;
	if (wDeck[x].face == "A"){
		printf("想變成1還是變成11呢?\n");
		scanf("%d", &userInput);
		if (userInput == 1)
			grade = 1;
		else
			grade = 11;
	}
	if (wDeck[x].face == "2") grade = 2;
	if (wDeck[x].face == "3") grade = 3;
	if (wDeck[x].face == "4") grade = 4;
	if (wDeck[x].face == "5") grade = 5;
	if (wDeck[x].face == "6") grade = 6;
	if (wDeck[x].face == "7") grade = 7;
	if (wDeck[x].face == "8") grade = 8;
	if (wDeck[x].face == "9") grade = 9;
	if (wDeck[x].face == "10") grade = 10;
	if (wDeck[x].face == "J") grade = 10;
	if (wDeck[x].face == "Q") grade = 10;
	if (wDeck[x].face == "K") grade = 10;
	return grade;
}

void play(Card * const wDeck, int boilingPoint)
{
	int cnt = 4, aWantToContinue = 1, bWantToContinue = 1, aGrade = getGrade(wDeck, 0) + getGrade(wDeck, 1), bGrade = 0;
	printf("玩家A底牌為:%s %s\n", wDeck[0], wDeck[1]);
	printf("(A)目前點數%d\n\n", aGrade);
	while (aWantToContinue != 0)
	{
		printf("請問是否要抽牌呢?要的話請輸入1,不要的話請輸入0.\n");
		scanf("%d", &aWantToContinue);
		if (aWantToContinue == 1)
		{
			printf("您(A)抽到%s\n", wDeck[cnt].face);

			aGrade = aGrade + getGrade(wDeck, cnt);
			cnt = cnt + 1;

		}
		if (aGrade>21)
		{
			printf("玩家A的點數:%d  爆掉了-->玩家B WIN!!!", aGrade);
			return 0;
		}



		printf("(A)目前點數%d\n\n", aGrade);
	}
	bGrade = getGrade(wDeck, 2) + getGrade(wDeck, 3);
	printf("玩家B底牌為:%s %s\n", wDeck[2], wDeck[3]);
	printf("(B)目前點數%d\n\n", bGrade);
	while (bWantToContinue != 0)
	{

		printf("請問是否要抽牌呢?要的話請輸入1,不要的話請輸入0.\n");
		scanf("%d", &bWantToContinue);
		if (bWantToContinue == 1)
		{

			printf("您(B)抽到%s\n", wDeck[cnt + 1].face);
			bGrade = bGrade + getGrade(wDeck, cnt + 1);
			cnt = cnt + 1;
		}
		if (bGrade>21)
		{
			printf("玩家B的點數:%d  爆掉了-->玩家A WIN!!!", bGrade);
			return 0;
		}



		printf("(B)目前點數%d\n\n", bGrade);
	}
	printf("最後點數 A:%d  B:%d\n", aGrade, bGrade);
	if (aGrade > bGrade)
	{
		printf("玩家A WIN!!!\n");
	}
	if (bGrade > aGrade)
	{
		printf("玩家B WIN!!!\n");
	}
	if (bGrade == aGrade)
	{
		printf("雙方平手\n");
	}




}