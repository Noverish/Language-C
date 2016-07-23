#include "essential.h"
#define BODY_NUMBER 6
#define COMPANY_NUMBER 7
#define STORE_NUMBER 7
#define PARTTIME_NUMBER 7
#define CONTEST_NUMBER 7

word body[BODY_NUMBER];
word company[COMPANY_NUMBER];
word store[STORE_NUMBER];
word partTime[PARTTIME_NUMBER];
word contest[CONTEST_NUMBER];
long long virualMoney;

void BuySellStock(void) {
	int i;
	int order=0;
	int unit=1;
	char key;
	int amount[STOCK_NUMBER+1]={0};

	DrawBoard();

	while(1) {
		printxy(4,12,"�����Ͻ� ������ ���Ͻð� ENTER�� ��������\n");
		SetColor(GREEN); printxy(4,14,"�ֽ� �̸�     ���簡��       ���� ����       �Ÿ� ����\n"); SetColor(WHITE);

		for(i=0;i<STOCK_NUMBER;i++) {
			printxy(4,15+i,stock[i].name);
			gotoxy(18,15+i); printf("%8s",MoneywithComma(stock[i].price));
			gotoxy(33,15+i); printf("%7d��",player.stock[i][0]);
			if(i==order) SetColor(VIOLET);
			gotoxy(49,15+i); printf("%7d��",amount[i]);
			if(i==order) SetColor(WHITE);
		}
		
		if(order==STOCK_NUMBER) SetColor(VIOLET);
		gotoxy(47,15+STOCK_NUMBER); printf("%6d ����",unit);
		if(order==STOCK_NUMBER) SetColor(WHITE);

		if(order==STOCK_NUMBER+1) SetColor(VIOLET);
		printxy(50,15+STOCK_NUMBER+1,"�Ÿ�����");
		if(order==STOCK_NUMBER+1) SetColor(WHITE);

		key=getch();
		if(key==UP) {
			if(order>0) {
				order--;
			}
		}
		else if(key==DOWN) {
			if(order<=STOCK_NUMBER)
				order++;
		}
		else if(key==LEFT) {
			if(order==STOCK_NUMBER && unit>1) unit/=10;
			else amount[order]-=unit;
		}
		else if(key==RIGHT) {
			if(order==STOCK_NUMBER && unit<100000) unit*=10;
			else amount[order]+=unit;
		}
		else if(key=='S' || key=='s') {
			DrawMyStockonBoard();
		}
		else if(key=='b' || key=='B') {
			DrawMyPropertyonBoard();
		}
		else if(key==ESC) {
			break;
		}
		else if(key==ENTER) {
			if(order!=STOCK_NUMBER+1) {
				virualMoney = player.money;

				for(i=0;i<STOCK_NUMBER;i++) {
					if(amount[i]<0) {
						if(player.stock[i][0]<(-amount[i])) {
							SetColor(RED); printxy(4,15+STOCK_NUMBER,"������ �ִ� �ֽ� ������ �����մϴ�."); SetColor(WHITE); 
							break;
						}
						virualMoney-=amount[i]*stock[i].price;
					}
				}
				if(i==STOCK_NUMBER) {
					for(i=0;i<STOCK_NUMBER;i++) {
						if(amount[i]>0) {
							virualMoney-=amount[i]*stock[i].price;
							if(virualMoney<0) {
								SetColor(RED); printxy(4,15+STOCK_NUMBER,"������ �ִ� ���� �����մϴ�.            "); SetColor(WHITE); 
								break;
							}
							if(amount[i]+player.stock[i][0]>1000000) {
								SetColor(RED); printxy(4,15+STOCK_NUMBER,"�鸸 �� �̻� ���� �� �����ϴ�.          "); SetColor(WHITE);
								break;
							}
						}
					}
					if(i==STOCK_NUMBER) {
						for(i=0;i<STOCK_NUMBER;i++) {
							player.money-=amount[i]*stock[i].price;
							if(player.stock[i][0]+amount[i]!=0)
								player.stock[i][1]=((player.stock[i][0]*player.stock[i][1])+(amount[i]*stock[i].price))/(player.stock[i][0]+amount[i]);
							else
								player.stock[i][1]=0;

							player.stock[i][0]+=amount[i];
							amount[i]=0;
						}
						SetColor(YELLOW); printxy(4,15+STOCK_NUMBER,"�ŷ� �Ϸ�!                              "); 
						DrawMoneyonBoard(); 
					}
				}
			}
			else
				break;
		}
	}
	system("cls");
	DrawBoard();
	
	printLog("�ֽ� �ŸŰ� ����Ǿ����ϴ�.\n");
	printLog("�ֻ����� �����÷��� SPACE�� �����ּ���.\n");
	printLog("�޴��� �����÷��� ESC�� �����ּ���.\n");
}

void BuySellProperty(void) {
	int i;
	int order=0;
	char key;
	int amount[PROPERTY_NUMBER]={0};
	int topMargin=13;

	DrawBoard();

	while(1) {
		SetColor(GREEN); printxy(4,topMargin-1,"�ε��� �̸�               ���� ����         �Ÿ�\n"); SetColor(WHITE); 

		for(i=0;i<PROPERTY_NUMBER;i++) {
			printxy(4,topMargin+i,property[i].name);
			gotoxy(19,topMargin+i); printf("%20s",MoneywithComma(property[i].price));

			gotoxy(46,topMargin+i);
			if(i==order) SetColor(VIOLET);

			if(player.property[i][0]==0) printf("  ����");
			else printf("  �Ǹ�");
			
			if(i==order) SetColor(WHITE);
		}
		if(order==PROPERTY_NUMBER) SetColor(VIOLET);
		printxy(44,topMargin+PROPERTY_NUMBER,"�Ÿ�����");
		if(order==PROPERTY_NUMBER) SetColor(WHITE);

		key=getch();
		if(key==UP) {
			if(order>0) {
				order--;
			}
		}
		else if(key==DOWN) {
			if(order<PROPERTY_NUMBER)
				order++;
		}
		else if(key=='S' || key=='s') {
			DrawMyStockonBoard();
		}
		else if(key=='B' || key=='b') {
			DrawMyPropertyonBoard();
		}
		else if(key==ESC) {
			break;
		}
		else if(key==ENTER) {
			if(order!=PROPERTY_NUMBER) {
				if(player.property[order][0]==0) {
					if(player.money<property[order].price) {
						SetColor(RED); printxy(4,topMargin+PROPERTY_NUMBER,"���� ���� �����մϴ�."); SetColor(WHITE); 
					}
					else {
						player.money-=property[order].price;
						player.property[order][0]++;
						player.property[order][1] = property[order].price;
						SetColor(YELLOW); printxy(4,topMargin+PROPERTY_NUMBER,"���� �Ϸ�!           "); 
						DrawMoneyonBoard(); 
					}
				}
				else {
					player.money+=property[order].price;
					player.property[order][0]--;
					SetColor(YELLOW); printxy(4,topMargin+PROPERTY_NUMBER,"�Ǹ� �Ϸ�!           "); 
					DrawMoneyonBoard(); 
				}
			}
			else
				break;
		}
	}

	system("cls");
	DrawBoard();

	printLog("�ε��� �ŸŰ� ����Ǿ����ϴ�.\n");
	printLog("�ֻ����� �����÷��� SPACE�� �����ּ���.\n");
	printLog("�޴��� �����÷��� ESC�� �����ּ���.\n");
}


void Earthquake(void) {
	
	printLog("������ �߻��߽��ϴ�.\n"); 

	virualMoney = Random(-3,8)*100;

	if(virualMoney>0) {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("(��)�� ���ƽ��ϴ�.\n");
		printLog("��������� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �޾ҽ��ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("������ ��ġ�� �ʾҽ��ϴ�.\n");
	}
	else {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog(" (��)�� ���ƽ��ϴ�.\n");
		printLog("ġ���� ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Fire(void) {
	
	printLog("ȭ�簡 �߻��߽��ϴ�.\n"); 

	virualMoney = Random(-4,6)*100;

	if(virualMoney>0) {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("�� ȭ���� �Ծ����ϴ�.\n");
		printLog("��������� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �޾ҽ��ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("������ ��ġ�� �ʾҽ��ϴ�.\n");
	}
	else {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("�� ȭ���� �Ծ����ϴ�.\n");
		printLog("ġ���� ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Robbery(void) {

	printLog("���� ������ ������ϴ�.\n");

	virualMoney = Random(-4,5)*100;

	if(virualMoney>0) {
		printLog("������ ���� ��Ҵ��� ��������� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �޾ҽ��ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("������ ������ ���� ���� ���������ϴ�.\n");
	}
	else {
		printLog("������ ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� ���İ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Company(void) {

	printLog(company[Random(0,COMPANY_NUMBER-1)].name);
	printLog(" ȸ�縦 ���Ƚ��ϴ�.\n");

	virualMoney = Random(-30,70)*10000;

	if(virualMoney>0) {
		printLog("����� ��â�ؼ� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �������ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("����� �� �� �ż� ����ġ�⸸ �߽��ϴ�.\n");
	}
	else {
		printLog("����� ���ؼ� ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �Ҿ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Horse(void) {

	printLog("�渶�忡 �����ϴ�.\n");

	virualMoney = Random(-40,80)*100;

	if(virualMoney>0) {
		printLog("���� �ɾ��� ���� �̰ܼ� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �������ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("������ �ΰ� ���ͼ� ���� �� �ɾ����ϴ�.\n");
	}
	else {
		printLog("���� �ɾ��� ���� ���� ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �Ҿ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Depression(void) {
	int i;
	
	printLog("���Ȳ�� �߻��Ͽ����ϴ�.\n");
	printLog("�ֽİ� �ε��� ���� ���� �Ͽ����ϴ�.\n");

	for(i=0;i<STOCK_NUMBER;i++) {
		stock[i].price*=(Random(70,90)/(double)100);
	}

	for(i=0;i<PROPERTY_NUMBER;i++) {
		property[i].price*=(Random(70,90)/(double)100);
	}

	DrawMoneyonBoard();
}

void Prosperity(void) {
	int i;
	
	printLog("ȣ����Դϴ�!\n");
	printLog("�ֽİ� �ε��� ���� ���� �Ͽ����ϴ�.\n");

	for(i=0;i<STOCK_NUMBER;i++) {
		stock[i].price*=(Random(120,140)/(double)100);
	}

	for(i=0;i<PROPERTY_NUMBER;i++) {
		property[i].price*=(Random(120,140)/(double)100);
	}

	DrawMoneyonBoard();
}

void oddEvenGame(void) {
	if(player.money<=0) {
		printLog("�� ������ Ȧ¦���� ���� ��!");
		return;
	}

	printLog("Ȧ¦�����Դϴ�.\n");
	printLog("���� �ݾ��� ���� ���� 10% �Դϴ�.\n");
	printLog("���� �ݾ��� �̱� �� ���� 2�谡 �˴ϴ�.\n");
	printLog("Ȧ¦�� �����Ͻð� ENTER�� �����ּ���.\n");
	SetColor(GREEN);
	printLog("�� ���� �ϱ� ������ ���� �� �����ϴ�.\n");
	SetColor(WHITE);

	long long battingMoney = player.money/10;
	long long earnMoney = 0;
	int num=1;
	int key;

	while(1) {
		if(num==1) SetColor(VIOLET); printxy(4,18,"Ȧ");
		SetColor(WHITE);
		if(num==2) SetColor(VIOLET); printxy(8,18,"¦");
		SetColor(YELLOW);
		gotoxy(4,20); printf("���ñݾ� : %s",MoneywithComma(battingMoney));
		gotoxy(4,21); printf("��    �� : %s",MoneywithComma(earnMoney));
		SetColor(WHITE);

		key=getch();

		if(key==LEFT) {
			num=1;
		}
		else if(key==RIGHT) {
			num=2;
		}
		else if(key==ENTER) {
			if(num==Random(1,2)) {
				printLog("clearlog");
				printLog("���߼̽��ϴ�!\n");
				printLog("Ȧ¦�� �����Ͻð� ENTER�� �����ּ���.\n");
				printLog("�׸� �ν÷��� ESC�� �����ּ���.\n");
				earnMoney += battingMoney;
				battingMoney *= 2;
			}
			else {
				printLog("clearlog");
				printLog("Ʋ�Ƚ��ϴ�...\n");
				earnMoney -= battingMoney;
				printLog("�� ");
				SetColor(RED); printLog(MoneywithComma(earnMoney)); SetColor(WHITE);
				printLog("�� �Ҿ����ϴ�.\n");
				printLog("�λ������� �����Ͻ÷��� SPACE�� �����ּ���.");
				player.money+=earnMoney;
				DrawMoneyonBoard();
				break;
			}
		} 
		else if(key==ESC && earnMoney!=0) {
			printLog("clearlog");
			printLog("�׸��ξ����ϴ�.\n");
			printLog("�� ");
			SetColor(YELLOW); printLog(MoneywithComma(earnMoney)); SetColor(WHITE);
			printLog("�� �������ϴ�.\n");
			printLog("�λ������� �����Ͻ÷��� SPACE�� �����ּ���.");
			player.money+=earnMoney;
			DrawMoneyonBoard();
			break;
		} 
		else if(key=='S' || key=='s') {
			DrawMyStockonBoard();
		}
		else if(key=='b' || key=='B') {
			DrawMyPropertyonBoard();
		}
	}
}

void Store(void) {

	printLog(store[Random(0,STORE_NUMBER-1)].name);
	printLog("(��)�� ���Ƚ��ϴ�.\n");

	virualMoney = Random(-30,70)*1000;

	if(virualMoney>0) {
		printLog("���԰� ��â�ؼ� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �������ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("���԰� �� �� �ż� ����ġ�⸸ �߽��ϴ�.\n");
	}
	else {
		printLog("���԰� ���ؼ� ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �Ҿ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void PartTime(void) {

	char sen[100];
	strcpy(sen,partTime[Random(0,PARTTIME_NUMBER-1)].name);
	printLog(sen);
	printLog(" �Ƹ�����Ʈ�� �߽��ϴ�.\n");

	virualMoney = Random(0,70)*100;
	if(strcmp("�ù� ������",sen)==0) virualMoney = -1000;

	if(virualMoney>0) {
		printLog("������ ���ؼ� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �������ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("�Ǽ��� ��û �ؼ� �Ѱܳ����ϴ�.\n");
	}
	else if (virualMoney<0) {
		printLog("�Ľ� ������ ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Contest(void) {

	printLog(contest[Random(0,CONTEST_NUMBER-1)].name);
	printLog(" ��ȸ�� �����Ͽ����ϴ�.\n");

	virualMoney = Random(-20,50)*1000;

	if(virualMoney>0) {
		printLog("��ȸ���� ����ؼ� ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �޾ҽ��ϴ�.\n");
	}
	else if (virualMoney==0) {
		printLog("�ƽ��Ե� ��ȸ���� Ż���Ͽ����ϴ�.\n");
	}
	else {
		printLog("�ʹ� ������ �ؼ� ");
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("(��)�� ���ƽ��ϴ�.\n");
		printLog("ġ���� ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� ����ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Beg(void) {

	if(player.money>0) {
		printLog("����ö�� ����ڿ��� ");
		virualMoney = Random(-50,-10)*10;
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �־����ϴ�.\n");
	}
	else {
		printLog("�ʹ� ���� ��� ����ö ������ ������ �߽��ϴ�.\n");
		printLog("�� ū ���ڿ��� ");
		virualMoney = Random(10,100)*1000;
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("�� �޾ҽ��ϴ�.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void SocialNews(void) {

	int i;
	int companyNum[2]={100,100};
	int noNews=0;

	for(i=0;i<2;i++) {

		for(companyNum[i] = Random(0,STOCK_NUMBER-1);i==1 && companyNum[i]==companyNum[0];companyNum[i] = Random(0,STOCK_NUMBER-1));

		char company[50];
		strcpy(company,stock[companyNum[i]].name);
	
		virualMoney = Random(-2,4);
		if(virualMoney>0) {
			printLog(company);
			printLog("(��)�� �ְ��� ������ �÷Ƚ��ϴ�.\n");
			printLog(company);
			printLog("�� �ֽ��� �����Ͽ����ϴ�.\n");
			stock[companyNum[i]].price *= (double)Random(120,130)/100;
			printLog("\n");
		}
		else if(virualMoney==0) {
			noNews++;
		}
		else {
			printLog(company);
			printLog("(��)�� �־��� ������ �½��ϴ�.\n");
			printLog(company);
			printLog("�� �ֽ��� �����Ͽ����ϴ�.\n");
			stock[companyNum[i]].price *= (double)Random(70,90)/100;
			printLog("\n");
		}
	}

	if(noNews==2) {
		printLog("������ �ƹ��� ��ȸ ������ �����ϴ�.");
	}
	DrawMoneyonBoard();

}


void GenerateContents(void) {

	strcpy(contents[0].name,"�ֽ�");
	contents[0].function=BuySellStock;
	strcpy(contents[1].name,"�ε���");
	contents[1].function=BuySellProperty;
	strcpy(contents[2].name,"����");
	contents[2].function=Earthquake;
	strcpy(contents[3].name,"���̾�");
	contents[3].function=Fire;
	strcpy(contents[4].name,"����");
	contents[4].function=Robbery;
	strcpy(contents[5].name,"���");
	contents[5].function=Company;
	strcpy(contents[6].name,"�渶");
	contents[6].function=Horse;
	strcpy(contents[7].name,"���Ȳ");
	contents[7].function=Depression;
	strcpy(contents[8].name,"ȣ���");
	contents[8].function=Prosperity;
	strcpy(contents[9].name,"Ȧ¦����");
	contents[9].function=oddEvenGame;
	strcpy(contents[10].name,"â��");
	contents[10].function=Store;
	strcpy(contents[11].name,"�Ƹ�����Ʈ");
	contents[11].function=PartTime;
	strcpy(contents[12].name,"��ȸ����");
	contents[12].function=Contest;
	strcpy(contents[13].name,"����");
	contents[13].function=Beg;
	strcpy(contents[14].name,"��ȸ����");
	contents[14].function=SocialNews;
}

void GenerateWords(void) {
	strcpy(body[0].name,"�ٸ�");
	strcpy(body[1].name,"��..�ű�");
	strcpy(body[2].name,"��");
	strcpy(body[3].name,"�Ӹ�");
	strcpy(body[4].name,"��ų������");
	strcpy(body[5].name,"��");

	strcpy(company[0].name,"�Ǽ�");
	strcpy(company[1].name,"����");
	strcpy(company[2].name,"����");
	strcpy(company[3].name,"�ε���");
	strcpy(company[4].name,"����");
	strcpy(company[5].name,"���");
	strcpy(company[6].name,"�ߵ�");

	strcpy(store[0].name,"���̹�");
	strcpy(store[1].name,"�̿��");
	strcpy(store[2].name,"ġŲ��");
	strcpy(store[3].name,"������");
	strcpy(store[4].name,"�н���");
	strcpy(store[5].name,"�߱���");
	strcpy(store[6].name,"�ڵ��� �븮��");

	strcpy(partTime[0].name,"���̹�");
	strcpy(partTime[1].name,"�̿��");
	strcpy(partTime[2].name,"ġŲ��");
	strcpy(partTime[3].name,"������");
	strcpy(partTime[4].name,"�н���");
	strcpy(partTime[5].name,"�߱���");
	strcpy(partTime[6].name,"�ù� ������");

	strcpy(contest[0].name,"�ƹ� �͵� ���ϱ�");
	strcpy(contest[1].name,"ġŲ �տ��� ���� ����");
	strcpy(contest[2].name,"��Ҹ��� ������ ��Ʈ����");
	strcpy(contest[3].name,"63���� ����â ���� �۱�");
	strcpy(contest[4].name,"���������� ��� ���̱�");
	strcpy(contest[5].name,"����ƾ �Ƕ� �뷡 ���� ���");
	strcpy(contest[6].name,"��ȸ���� ���� ���� Ż���ϱ�");
}