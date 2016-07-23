#include "essential.h"

void gotoxy(int x, int y) {
    COORD Pos = { x-1, y-1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int Random(int a, int b) {
	int random;

	if(a>b) {
		int swap;
		swap = a;
		a= b;
		b= swap;
	}

	srand((unsigned)time(NULL)*rand()+rand());
	random = rand();
	return random%(b-a+1)+a;
}

inline char* MoneywithCommaint(_In_ int money)
{return (MoneywithComma((long long)money)); }

char* MoneywithComma(long long money) {
	int i;
	int lenght;
	int minusMoney=1;
	char trash[30]={0};

	if(money<0) {
		money*=-1;
		minusMoney=-1;
	}
	else if(money==0)
		minusMoney=0;
	
	number[29]=NULL;
	for(i=28;i>=0;i--) {
		number[i] = (money%10)+'0';
		money/=10;
	}
	strcpy(trash,number);
	for(i=0;i<29 && trash[i]=='0';i++);
	strcpy(number,trash+i);
	
	lenght = strlen(number)-3;

	for(;lenght>0;lenght-=3) {
		strcpy(trash,number+lenght);
		strcpy(number+lenght+1,trash);
		number[lenght]=',';
	}

	strcpy(trash,number);
	if(minusMoney==0) strcpy(number,"$0");
	else strcpy(number,"$");
	strcat(number,trash);

	if(minusMoney==-1) {
		strcpy(trash,number);
		strcpy(number,"-");
		strcat(number,trash);
	}

	return number;
}

void printxy(int x, int y, char* sen) {
	gotoxy(x,y);
	printf("%s",sen);
}

void printLog(char originSen[]) {
	static int y = 12;
	static int x = 4;
	static char log[1000];
	int lenght = strlen(originSen);

	if(strcmp(originSen,"clearlog")==0) {
		DrawBoard();
		x=4;
		y=12;
		log[0]=NULL;
		return;
	}
	else if(strcmp(originSen,"roadlog")==0) {
		DrawBoard();
		printxy(4,12,log);
		return;
	}

	printxy(x,y,originSen);

	strcat(log,originSen);

	if(originSen[lenght-1]=='\n') {
		y++;
		x=4;
		strcat(log,"   ");
	}
	else {
		x+=lenght;
	}
	
	
}