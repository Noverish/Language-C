#include "essential.h"

int main() {
	char key;

	while(1) {
		switch(GameMenu()) {
		case 1 : {
			PlayGame(); //PlayGame.cpp ���Ͽ� ����.
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
	printxy(7,3,"�����ᡡ����");
	printxy(7,4,"�ᡡ�����ᡡ��");
	printxy(7,5,"�ᡡ�����ᡡ��");
	printxy(7,6,"�ᡡ�����ᡡ��");
	printxy(7,7,"�����ᡡ����");
	printxy(7,8,"��������������");
	printxy(7,9,"��������������");
	printxy(7,10,"���ᡡ��������");
	printxy(7,11,"���ᡡ��������");
	printxy(7,12,"���������");

	SetColor(YELLOW);
	printxy(23,3,"�����ᡡ�����ᡡ��");
	printxy(23,4,"�����ᡡ�����ᡡ��");
	printxy(23,5,"���ᡡ�ᡡ������");
	printxy(23,6,"���ᡡ�ᡡ���ᡡ��");
	printxy(23,7,"�ᡡ�����ᡡ�ᡡ��");
	printxy(23,8,"������������������");
	printxy(23,9,"�����������ᡡ");
	printxy(23,10,"�����ᡡ����������");
	printxy(23,11,"�����ᡡ����������");
	printxy(23,12,"�����������ᡡ");

	SetColor(SKYBLUE);
	printxy(43,3,"����ᡡ�ᡡ��");
	printxy(43,4,"�������ᡡ�ᡡ��");
	printxy(43,5,"�������ᡡ�ᡡ��");
	printxy(43,6,"���������ᡡ��");
	printxy(43,7,"�������ᡡ�ᡡ��");
	printxy(43,8,"�����ᡡ���ᡡ��");
	printxy(43,9,"�����ᡡ���ᡡ��");
	printxy(43,10,"���ᡡ�����ᡡ��");
	printxy(43,11,"�ᡡ�������ᡡ��");
	printxy(43,12,"�����������ᡡ��");

	SetColor(GREEN);
	printxy(61,3,"�����ᡡ����");
	printxy(61,4,"�ᡡ�����ᡡ��");
	printxy(61,5,"�ᡡ�����ᡡ��");
	printxy(61,6,"�ᡡ�����ᡡ��");
	printxy(61,7,"�����ᡡ����");
	printxy(61,8,"��������������");
	printxy(61,9,"���������");
	printxy(61,10,"���ᡡ��������");
	printxy(61,11,"���ᡡ��������");
	printxy(61,12,"���������");

	SetColor(VIOLET); printxy(30,16,"(1)  ��  ��  ��  ��");
	SetColor(YELLOW); printxy(30,18,"(2)  ��  ��  ��  ��");
	SetColor(SKYBLUE); printxy(30,20,"(3)  ��    ��    ȭ");
	SetColor(GREEN); printxy(28,22,"(ESC)  ��  ��  ��  ��");
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

	gotoxy(4,3); printf("SPACE�� ������ �ֻ����� �����ϴ�.");
	gotoxy(4,4); printf("�� ���� ������ ���� �ڵ� ���� �˴ϴ�.");
	gotoxy(4,5); printf("�� ���� ������ ���� �ֽİ� �ε��� ���� �䵿Ĩ�ϴ�.");
	gotoxy(4,6); printf("���� �߿� ESCŰ�� ������ �޴��� ���ư��ϴ�.");
	
	gotoxy(4,8); printf("���� �߿� SŰ�� ������ ���� ���� �ֽ� â�� ��ϴ�.");
	gotoxy(4,9); printf("���� �߿� BŰ�� ������ ���� ���� �ε��� â�� ��ϴ�.");

	gotoxy(4,11); printf("���� ���������� �ֽ�, �ε���, ����, ȭ��, ����, ���, �渶, ��ȸ����,");
	gotoxy(4,12); printf("���Ȳ, ȣ���, Ȧ¦����, â��, �Ƹ�����Ʈ, ��ȸ����, ������ �ֽ��ϴ�.");
	gotoxy(4,13); printf("�ֽ��� �Ÿ� �� �� ���� ����Ű�� ������ ���� ���ڰ� �����ϰ�");
	gotoxy(4,14); printf("���� ����Ű�� ������ ���� ���ڰ� �����մϴ�.");
	gotoxy(4,15); printf("���� ���ڰ� ����̸� �ֽ��� ��� ���̰� �����̸� �Ĵ� ���Դϴ�.");
	gotoxy(4,16); printf("�ֽ��� �Ÿ� �� �� ���� ������ �̿��ؼ� �� ���� ���� �Ÿ� �� �� �ֽ��ϴ�.");
	
	SetColor(DARK_SKYBLUE); gotoxy(4,18); printf("�޴��� ���ư����� ESCŰ�� ��������."); SetColor(WHITE); 

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
	printxy(28,8,"���������� ���µǾ����ϴ�.");
	printxy(26,9,"���ư��÷��� ESCŰ�� ��������."); 
	SetColor(WHITE);

	while((key = getch())!=ESC);
}