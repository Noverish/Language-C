#include "essential.h"

int main() {
	char key;

	while(1) {
		switch(GameMenu()) {
		case 1 : {
			PlayGame(); //PlayGame.cpp 파일에 있음.
			break;
				 }
		case 2 : {
			GameRule();
			break;
				 }
		case 3 : {
			GameReset();
			break;
				 }
		case ESC : {
			system("cls");
			exit(0);
				 }
		}
	}
	return 0;
}

int GameMenu(void) {
	char number;
	
	system("cls");

	SetColor(VIOLET);
	printxy(7,3,"　■■■　　■");
	printxy(7,4,"■　　　■　■");
	printxy(7,5,"■　　　■　■");
	printxy(7,6,"■　　　■　■");
	printxy(7,7,"　■■■　　■");
	printxy(7,8,"　　　　　　■");
	printxy(7,9,"　　　　　　■");
	printxy(7,10,"　■　　　　　");
	printxy(7,11,"　■　　　　　");
	printxy(7,12,"　■■■■■■");

	SetColor(YELLOW);
	printxy(23,3,"　　■　　　■　■");
	printxy(23,4,"　　■　　　■　■");
	printxy(23,5,"　■　■　　■■■");
	printxy(23,6,"　■　■　　■　■");
	printxy(23,7,"■　　　■　■　■");
	printxy(23,8,"　　　　　　　　　");
	printxy(23,9,"　　　■■■■■　");
	printxy(23,10,"　　■　　　　　■");
	printxy(23,11,"　　■　　　　　■");
	printxy(23,12,"　　　■■■■■　");

	SetColor(SKYBLUE);
	printxy(43,3,"■■■■　■　■");
	printxy(43,4,"　　　■　■　■");
	printxy(43,5,"　　　■　■　■");
	printxy(43,6,"　　　■■■　■");
	printxy(43,7,"　　　■　■　■");
	printxy(43,8,"　　■　　■　■");
	printxy(43,9,"　　■　　■　■");
	printxy(43,10,"　■　　　■　■");
	printxy(43,11,"■　　　　■　■");
	printxy(43,12,"　　　　　■　■");

	SetColor(GREEN);
	printxy(61,3,"　■■■　　■");
	printxy(61,4,"■　　　■　■");
	printxy(61,5,"■　　　■　■");
	printxy(61,6,"■　　　■　■");
	printxy(61,7,"　■■■　　■");
	printxy(61,8,"　　　　　　　");
	printxy(61,9,"　■■■■■■");
	printxy(61,10,"　■　　　　■");
	printxy(61,11,"　■　　　　■");
	printxy(61,12,"　■■■■■■");

	SetColor(VIOLET); printxy(30,16,"(1)  게  임  시  작");
	SetColor(YELLOW); printxy(30,18,"(2)  게  임  방  법");
	SetColor(SKYBLUE); printxy(30,20,"(3)  초    기    화");
	SetColor(GREEN); printxy(28,22,"(ESC)  게  임  종  료");
	SetColor(WHITE);

	while(1) {
		number = getch();
		if('1' <= number && number <= '3') {
			return number-'0';
		} else if(number==ESC) {
			return ESC;
		}
	}
	
}

void GameRule(void) {
	char key;
	
	system("cls");

	gotoxy(4,3); printf("SPACE를 누르면 주사위를 던집니다.");
	gotoxy(4,4); printf("한 턴이 끝날때 마다 자동 저장 됩니다.");
	gotoxy(4,5); printf("한 턴이 끝날때 마다 주식과 부동산 값이 요동칩니다.");
	gotoxy(4,6); printf("게임 중에 ESC키를 누르면 메뉴로 돌아갑니다.");
	
	gotoxy(4,8); printf("게임 중에 S키를 누르면 내가 가진 주식 창이 뜹니다.");
	gotoxy(4,9); printf("게임 중에 B키를 누르면 내가 가진 부동산 창이 뜹니다.");

	gotoxy(4,11); printf("게임 컨텐츠에는 주식, 부동산, 지진, 화재, 강도, 사업, 경마, 사회뉴스,");
	gotoxy(4,12); printf("대공황, 호경기, 홀짝게임, 창업, 아르바이트, 대회참가, 구걸이 있습니다.");
	gotoxy(4,13); printf("주식을 매매 할 때 좌측 방향키를 누르면 구매 숫자가 감소하고");
	gotoxy(4,14); printf("우측 방향키를 누르면 구매 숫자가 증가합니다.");
	gotoxy(4,15); printf("구매 숫자가 양수이면 주식을 사는 것이고 음수이면 파는 것입니다.");
	gotoxy(4,16); printf("주식을 매매 할 때 밑의 단위를 이용해서 한 번에 많이 매매 할 수 있습니다.");
	
	SetColor(DARK_SKYBLUE); gotoxy(4,18); printf("메뉴로 돌아가려면 ESC키를 누르세요."); SetColor(WHITE); 

	while(1) {
		key=getch();
		if(key==ESC) 
			break;
	}
}

void GameReset(void) {
	int i,j,key;

	printLog("clearlog");
	system("cls");

	ResetStockData();
	ResetPropertyData();
	ResetPlayerData();

	SetColor(RED); 
	printxy(28,8,"정상적으로 리셋되었습니다.");
	printxy(26,9,"돌아가시려면 ESC키를 누르세요."); 
	SetColor(WHITE);

	while((key = getch())!=ESC);
}