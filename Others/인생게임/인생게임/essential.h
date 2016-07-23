#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define WIDTH 77 //CMDâ �ʺ�
#define HEIGHT 25 //CMDâ ����
#define ESC 27 //ESC �ƽ�Ű �ڵ�
#define ENTER 13 //ENTER �ƽ�Ű �ڵ�
#define LEFT 75 //���� ����Ű �ƽ�Ű �ڵ�
#define RIGHT 77 // ���� ����Ű �ƽ�Ű �ڵ�
#define UP 72 //���� ����Ű �ƽ�Ű �ڵ�
#define DOWN 80 //�Ʒ��� ����Ű �ƽ�Ű �ڵ�
#define CONTENTS_NUMBER 15 //�������� �� ����
#define STOCK_NUMBER 6 //�ֽ��� �� ����
#define PROPERTY_NUMBER 11 //�ε����� �� ����
#define INTMAX 2147483647 //2,147,483,647
#define MAX_MONEY 1000000000000 //1��


//essential.cpp
void gotoxy(int x, int y); 
void SetColor(int color);
int Random(int a, int b);
char* __cdecl MoneywithCommaint(_In_ int money);
char* MoneywithComma(long long money);
void printxy(int x, int y, char sen[]);
void printLog(char originSen[]);

//Data.cpp
void ResetStockData(void);
void ResetPropertyData(void);
void ResetPlayerData(void);
void SaveData(void);
void RoadData(void);

//ContentsData.cpp
void GenerateContents(void);
void GenerateWords(void);

//DrawGameBoard.cpp
void DrawBoard(void);
void DrawMoneyonBoard(void);
void PrintName(char name[], int order);
void DrawDice(int num, int order);
void DrawMyStockonBoard(void);
void DrawMyPropertyonBoard(void);

//PlayGame.cpp
void PlayGame(void);
void MovingPlayer(int distance);
int ThrowDice(void);
void WavingPrice(void);


//main.cpp
int GameMenu(void);
void GameRule(void);
void GameReset(void);

typedef struct Board {
	char name[20];
	void (*function)(void);
};
extern Board contents[50];

typedef struct Player {
	int board[9];
	long long money;
	int turns;
	int gold;
	int dice[2];
	long long stock[STOCK_NUMBER][2];//������, �춧����
	long long property[PROPERTY_NUMBER][2];
};
extern Player player;

typedef struct Asset {
	char name[20];
	long long price;
};
extern Asset stock[STOCK_NUMBER];
extern Asset property[PROPERTY_NUMBER];

typedef struct word {
	char name[200];
};

enum {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_SKYBLUE, DARK_RED, DARK_VIOLET, DARK_YELLOW, GRAY, DARK_GRAY, 
	            BLUE,      GREEN,      SKYBLUE,      RED,      VIOLET,      YELLOW, WHITE
};

extern char number[30];
