#include "essential.h"

Player player;

void PlayGame(void) {

	char key;
	int diceNum;
	int boardnum[9];

	RoadData();
	printLog("roadlog");
	printLog("주사위를 던지시려면 SPACE를 눌러주세요.\n");
	printLog("메뉴로 나가시려면 ESC를 눌러주세요.\n");
	
	while(1){
		
		key = getch();
		if(key==' ') {
			printLog("clearlog");
			player.turns++;
			WavingPrice();
			diceNum = ThrowDice();
			MovingPlayer(diceNum);
			contents[player.board[0]].function();
			SaveData();
		}
		else if(key==ESC) {
			SaveData();
			break;
		}
		else if(key=='s' || key=='S') {
			DrawMyStockonBoard();
		}
		else if(key=='b' || key=='B') {
			DrawMyPropertyonBoard();
		}
	}
}

void MovingPlayer(int distance) {
	for(;distance>0;distance--) {
		Sleep(200);
		int i;
		for(i=0;i<8;i++) {
			player.board[i]=player.board[i+1];
			PrintName(contents[player.board[i]].name,i);
		}
		player.board[8]=Random(0,CONTENTS_NUMBER-1);
		PrintName(contents[player.board[8]].name,i);
	}
	
}

int ThrowDice(void) {
	int i=0;
	int num, sum=0;
	do {
		sum=0;

		DrawDice(num=(Random(1,6)),0); 
		player.dice[0]=num;
		sum+=num;

		DrawDice(num=(Random(1,6)),1);
		player.dice[1]=num;
		sum+=num;

		Sleep(50);
		i++;
	} while(i<20);

	return sum;
} 

void WavingPrice(void) {
	int i;
	static int degree=250;
	static int stockStandard = 10050;
	static int propertyStandard = 10050;

	for(i=0;i<STOCK_NUMBER;i++) {
		stock[i].price*=Random(stockStandard-degree,stockStandard+degree)/(double)10000;
	}

	for(i=0;i<PROPERTY_NUMBER;i++) {
		property[i].price*=Random(propertyStandard-degree,propertyStandard+degree)/(double)10000;
	}
}
