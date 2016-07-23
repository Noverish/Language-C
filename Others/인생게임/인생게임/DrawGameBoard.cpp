#include "essential.h"

void DrawBoard(void){
	int i;
	int dicex, dicey;

	system("cls");

	gotoxy(1,1); printf("\n");
	SetColor(GREEN); printf("　　현재칸\n");
	SetColor(GREEN); printf("　┏━━━┳"); SetColor(WHITE); printf("━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
	SetColor(GREEN); printf("　┃　　　┃"); SetColor(WHITE); printf("　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃\n");
	SetColor(GREEN); printf("　┃　　　┃"); SetColor(WHITE); printf("　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃\n");
	SetColor(GREEN); printf("　┃　　　┃"); SetColor(WHITE); printf("　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃　　　┃\n");
	SetColor(GREEN); printf("　┗━━━┻"); SetColor(WHITE); printf("━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
	DrawMoneyonBoard();
	SetColor(DARK_SKYBLUE);  gotoxy(35,9); printf("턴  수 : %9d 턴",player.turns);
	gotoxy(35,10); printf("주식(S)");
	gotoxy(47,10); printf("부동산(B)");
	SetColor(SKYBLUE);
	printxy(59, 8,"┏━━━┳━━━┓");
	printxy(59, 9,"┃　　　┃　　　┃");
	printxy(59,10,"┃　　　┃　　　┃");
	printxy(59,11,"┃　　　┃　　　┃");
	printxy(59,12,"┗━━━┻━━━┛");
	DrawDice(player.dice[0],0);
	DrawDice(player.dice[1],1);
	SetColor(WHITE);
	for(i=0;i<9;i++)
		PrintName(contents[player.board[i]].name,i);
}

void DrawMoneyonBoard(void) {

	long long asset = 0;
	int i;

	if(player.money>=0) SetColor(YELLOW);
	else SetColor(RED);
	gotoxy(4,9);
	printf("가 진 돈 : %19s",MoneywithComma(player.money));

	asset += player.money;

	for(i=0;i<STOCK_NUMBER;i++)
		asset += player.stock[i][0]*stock[i].price;

	for(i=0;i<PROPERTY_NUMBER;i++)
		asset += player.property[i][0]*property[i].price;

	if(asset>=0) SetColor(YELLOW);
	else SetColor(RED);
	gotoxy(4,10);
	printf("자산가치 : %19s",MoneywithComma(asset));

	SetColor(WHITE);
}

void PrintName(char name[], int order) {
	int x=5+8*order, y=4;
	int lenght = strlen(name)/2;

	printxy(x,y,"　　　");
	printxy(x,y+1,"　　　");
	printxy(x,y+2,"　　　");

	switch(lenght) {
	case 1 : {
		gotoxy(x+2,y+1); puts(name);
		break;
			 }
	case 2 : {
		gotoxy(x,y+1); printf("%c%c",name[0],name[1]);
		gotoxy(x+4,y+1); printf("%c%c",name[2],name[3]);
		break;
			 }
	case 3 : {
		gotoxy(x,y+1); puts(name);
		break;
			 }
	case 4 : {
		gotoxy(x,y);
		printf("%c%c　",name[0],name[1]);
		printf("%c%c",name[2],name[3]);
		gotoxy(x,y+2);
		printf("%c%c　",name[4],name[5]);
		printf("%c%c",name[6],name[7]);
		break;
			 }
	case 5 : {
		gotoxy(x,y);
		printf("%c%c",name[0],name[1]);
		printf("%c%c",name[2],name[3]);
		printf("%c%c",name[4],name[5]);
		gotoxy(x,y+2);
		printf("%c%c　",name[6],name[7]);
		printf("%c%c",name[8],name[9]);
		break;
			 }
	case 6 : {
		gotoxy(x,y);
		printf("%c%c",name[0],name[1]);
		printf("%c%c",name[2],name[3]);
		printf("%c%c",name[4],name[5]);
		gotoxy(x,y+2); puts(name+6);
		break;
			 }
	}
}

void DrawDice(int num, int order) {
	int x, y=9;

	if(order==0) x=61;
	else x=69;

	SetColor(SKYBLUE);
	switch(num) {
		case 1 : {
			gotoxy(x,y  ); printf("　　　");
			gotoxy(x,y+1); printf("　●　");
			gotoxy(x,y+2); printf("　　　");
			break;
				 }
		case 2 : {
			gotoxy(x,y  ); printf("●　　");
			gotoxy(x,y+1); printf("　　　");
			gotoxy(x,y+2); printf("　　●");
			break;
				 }
		case 3 : {
			gotoxy(x,y  ); printf("●　　");
			gotoxy(x,y+1); printf("　●　");
			gotoxy(x,y+2); printf("　　●");
			break;
				 }
		case 4 : {
			gotoxy(x,y  ); printf("●　●");
			gotoxy(x,y+1); printf("　　　");
			gotoxy(x,y+2); printf("●　●");
			break;
				 }
		case 5 : {
			gotoxy(x,y  ); printf("●　●");
			gotoxy(x,y+1); printf("　●　");
			gotoxy(x,y+2); printf("●　●");
			break;
				 }
		case 6 : {
			gotoxy(x,y  ); printf("●　●");
			gotoxy(x,y+1); printf("●　●");
			gotoxy(x,y+2); printf("●　●");
			break;
				 }
	}
	SetColor(WHITE);
}

void DrawMyStockonBoard(void) {
	char key;
	int line=0;
	int i;
	int topMargin = 13;

	DrawBoard();

	SetColor(GREEN); printxy(4,topMargin,"주식 이름    살때 가격    현재 가격         수량          나의 이득"); SetColor(WHITE); 

	for(i=0;i<STOCK_NUMBER;i++) {
		if(player.stock[i][0]==0) continue;

		line++;
		long long buyprice = player.stock[i][1];
		long long nowprice = stock[i].price;
		long long amount = player.stock[i][0];

		printxy(4,topMargin+line,stock[i].name);

		
		gotoxy(18,topMargin+line); printf("%8s",MoneywithComma(buyprice));
		gotoxy(31,topMargin+line); printf("%8s",MoneywithComma(nowprice));
		gotoxy(42,topMargin+line); printf("%8d주",amount);

		if(amount*(nowprice-buyprice)<0) SetColor(RED);
		else SetColor(YELLOW);

		gotoxy(52,topMargin+line); printf("%19s",MoneywithComma((long long)amount*(nowprice-buyprice)));

		SetColor(WHITE);
	}
	if(line==0)
		printxy(4,topMargin+2,"가진 주식이 없습니다.");

	printxy(4,topMargin+line+3,"빠져나가시려면 ESC를 누르세요.");

	while((key=getch())!=ESC);
	printLog("roadlog");
}

void DrawMyPropertyonBoard(void) {
	char key;
	int line=0;
	int i;
	int topMargin=13;

	DrawBoard();

	SetColor(GREEN); printxy(4,topMargin,"부동산 이름              살때 가격          현재 가격          나의 이득"); SetColor(WHITE); 

	for(i=0;i<PROPERTY_NUMBER;i++) {
		if(player.property[i][0]==0) continue;

		line++;
		long long buyprice = player.property[i][1];
		long long nowprice = property[i].price;

		printxy(4,topMargin+line,property[i].name);
		gotoxy(19,topMargin+line); printf("%19s",MoneywithComma(buyprice));
		gotoxy(38,topMargin+line); printf("%19s",MoneywithComma(nowprice));

		if(nowprice-buyprice<0) SetColor(RED);
		else SetColor(YELLOW);

		gotoxy(57,topMargin+line); printf("%19s",MoneywithComma(((long long)nowprice-buyprice)));

		SetColor(WHITE);
	}
	if(line==0)
		printxy(4,topMargin+2,"가진 부동산이 없습니다.");

	printxy(4,topMargin+line+3,"빠져나가시려면 ESC를 누르세요.");

	while((key=getch())!=ESC);
	printLog("roadlog");
}
