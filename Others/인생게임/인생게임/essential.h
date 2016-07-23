#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define WIDTH 77 //CMD창 너비
#define HEIGHT 25 //CMD창 높이
#define ESC 27 //ESC 아스키 코드
#define ENTER 13 //ENTER 아스키 코드
#define LEFT 75 //좌측 방향키 아스키 코드
#define RIGHT 77 // 우축 방향키 아스키 코드
#define UP 72 //위쪽 방향키 아스키 코드
#define DOWN 80 //아래쪽 방향키 아스키 코드
#define CONTENTS_NUMBER 15 //콘텐츠의 총 갯수
#define STOCK_NUMBER 6 //주식의 총 갯수
#define PROPERTY_NUMBER 11 //부동산의 총 갯수
#define INTMAX 2147483647 //2,147,483,647
#define MAX_MONEY 1000000000000 //1조


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
	long long stock[STOCK_NUMBER][2];//가진수, 살때가격
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
