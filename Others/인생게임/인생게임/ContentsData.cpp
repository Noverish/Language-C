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
		printxy(4,12,"구매하실 수량을 정하시고 ENTER를 누르세요\n");
		SetColor(GREEN); printxy(4,14,"주식 이름     현재가격       나의 수량       매매 수량\n"); SetColor(WHITE);

		for(i=0;i<STOCK_NUMBER;i++) {
			printxy(4,15+i,stock[i].name);
			gotoxy(18,15+i); printf("%8s",MoneywithComma(stock[i].price));
			gotoxy(33,15+i); printf("%7d주",player.stock[i][0]);
			if(i==order) SetColor(VIOLET);
			gotoxy(49,15+i); printf("%7d주",amount[i]);
			if(i==order) SetColor(WHITE);
		}
		
		if(order==STOCK_NUMBER) SetColor(VIOLET);
		gotoxy(47,15+STOCK_NUMBER); printf("%6d 단위",unit);
		if(order==STOCK_NUMBER) SetColor(WHITE);

		if(order==STOCK_NUMBER+1) SetColor(VIOLET);
		printxy(50,15+STOCK_NUMBER+1,"매매종료");
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
							SetColor(RED); printxy(4,15+STOCK_NUMBER,"가지고 있는 주식 수량이 부족합니다."); SetColor(WHITE); 
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
								SetColor(RED); printxy(4,15+STOCK_NUMBER,"가지고 있는 돈이 부족합니다.            "); SetColor(WHITE); 
								break;
							}
							if(amount[i]+player.stock[i][0]>1000000) {
								SetColor(RED); printxy(4,15+STOCK_NUMBER,"백만 주 이상 가질 수 없습니다.          "); SetColor(WHITE);
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
						SetColor(YELLOW); printxy(4,15+STOCK_NUMBER,"거래 완료!                              "); 
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
	
	printLog("주식 매매가 종료되었습니다.\n");
	printLog("주사위를 던지시려면 SPACE를 눌러주세요.\n");
	printLog("메뉴로 나가시려면 ESC를 눌러주세요.\n");
}

void BuySellProperty(void) {
	int i;
	int order=0;
	char key;
	int amount[PROPERTY_NUMBER]={0};
	int topMargin=13;

	DrawBoard();

	while(1) {
		SetColor(GREEN); printxy(4,topMargin-1,"부동산 이름               현재 가격         매매\n"); SetColor(WHITE); 

		for(i=0;i<PROPERTY_NUMBER;i++) {
			printxy(4,topMargin+i,property[i].name);
			gotoxy(19,topMargin+i); printf("%20s",MoneywithComma(property[i].price));

			gotoxy(46,topMargin+i);
			if(i==order) SetColor(VIOLET);

			if(player.property[i][0]==0) printf("  구매");
			else printf("  판매");
			
			if(i==order) SetColor(WHITE);
		}
		if(order==PROPERTY_NUMBER) SetColor(VIOLET);
		printxy(44,topMargin+PROPERTY_NUMBER,"매매종료");
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
						SetColor(RED); printxy(4,topMargin+PROPERTY_NUMBER,"가진 돈이 부족합니다."); SetColor(WHITE); 
					}
					else {
						player.money-=property[order].price;
						player.property[order][0]++;
						player.property[order][1] = property[order].price;
						SetColor(YELLOW); printxy(4,topMargin+PROPERTY_NUMBER,"구매 완료!           "); 
						DrawMoneyonBoard(); 
					}
				}
				else {
					player.money+=property[order].price;
					player.property[order][0]--;
					SetColor(YELLOW); printxy(4,topMargin+PROPERTY_NUMBER,"판매 완료!           "); 
					DrawMoneyonBoard(); 
				}
			}
			else
				break;
		}
	}

	system("cls");
	DrawBoard();

	printLog("부동산 매매가 종료되었습니다.\n");
	printLog("주사위를 던지시려면 SPACE를 눌러주세요.\n");
	printLog("메뉴로 나가시려면 ESC를 눌러주세요.\n");
}


void Earthquake(void) {
	
	printLog("지진이 발생했습니다.\n"); 

	virualMoney = Random(-3,8)*100;

	if(virualMoney>0) {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("(을)를 다쳤습니다.\n");
		printLog("보험금으로 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 받았습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("다행히 다치지 않았습니다.\n");
	}
	else {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog(" (을)를 다쳤습니다.\n");
		printLog("치료비로 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 썼습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Fire(void) {
	
	printLog("화재가 발생했습니다.\n"); 

	virualMoney = Random(-4,6)*100;

	if(virualMoney>0) {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("에 화상을 입었습니다.\n");
		printLog("보험금으로 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 받았습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("다행히 다치지 않았습니다.\n");
	}
	else {
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("에 화상을 입었습니다.\n");
		printLog("치료비로 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 썼습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Robbery(void) {

	printLog("집에 강도가 들었습니다.\n");

	virualMoney = Random(-4,5)*100;

	if(virualMoney>0) {
		printLog("강도를 때려 잡았더니 포상금으로 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 받았습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("강도가 현관의 개를 보고 도망갔습니다.\n");
	}
	else {
		printLog("강도가 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 훔쳐갔습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Company(void) {

	printLog(company[Random(0,COMPANY_NUMBER-1)].name);
	printLog(" 회사를 차렸습니다.\n");

	virualMoney = Random(-30,70)*10000;

	if(virualMoney>0) {
		printLog("사업이 번창해서 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 벌었습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("사업이 잘 안 돼서 본전치기만 했습니다.\n");
	}
	else {
		printLog("사업이 망해서 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 잃었습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Horse(void) {

	printLog("경마장에 갔습니다.\n");

	virualMoney = Random(-40,80)*100;

	if(virualMoney>0) {
		printLog("돈을 걸었던 말이 이겨서 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 벌었습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("지갑을 두고 나와서 돈을 못 걸었습니다.\n");
	}
	else {
		printLog("돈을 걸었던 말이 져서 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 잃었습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Depression(void) {
	int i;
	
	printLog("대공황이 발생하였습니다.\n");
	printLog("주식과 부동산 값이 폭락 하였습니다.\n");

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
	
	printLog("호경기입니다!\n");
	printLog("주식과 부동산 값이 폭등 하였습니다.\n");

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
		printLog("돈 없으면 홀짝게임 하지 마!");
		return;
	}

	printLog("홀짝게임입니다.\n");
	printLog("배팅 금액은 가진 돈의 10% 입니다.\n");
	printLog("배팅 금액은 이길 때 마다 2배가 됩니다.\n");
	printLog("홀짝을 결정하시고 ENTER를 눌러주세요.\n");
	SetColor(GREEN);
	printLog("한 판을 하기 전까진 나갈 수 없습니다.\n");
	SetColor(WHITE);

	long long battingMoney = player.money/10;
	long long earnMoney = 0;
	int num=1;
	int key;

	while(1) {
		if(num==1) SetColor(VIOLET); printxy(4,18,"홀");
		SetColor(WHITE);
		if(num==2) SetColor(VIOLET); printxy(8,18,"짝");
		SetColor(YELLOW);
		gotoxy(4,20); printf("배팅금액 : %s",MoneywithComma(battingMoney));
		gotoxy(4,21); printf("딴    돈 : %s",MoneywithComma(earnMoney));
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
				printLog("맞추셨습니다!\n");
				printLog("홀짝을 결정하시고 ENTER를 눌러주세요.\n");
				printLog("그만 두시려면 ESC를 눌러주세요.\n");
				earnMoney += battingMoney;
				battingMoney *= 2;
			}
			else {
				printLog("clearlog");
				printLog("틀렸습니다...\n");
				earnMoney -= battingMoney;
				printLog("총 ");
				SetColor(RED); printLog(MoneywithComma(earnMoney)); SetColor(WHITE);
				printLog("을 잃었습니다.\n");
				printLog("인생게임을 진행하시려면 SPACE를 눌러주세요.");
				player.money+=earnMoney;
				DrawMoneyonBoard();
				break;
			}
		} 
		else if(key==ESC && earnMoney!=0) {
			printLog("clearlog");
			printLog("그만두었습니다.\n");
			printLog("총 ");
			SetColor(YELLOW); printLog(MoneywithComma(earnMoney)); SetColor(WHITE);
			printLog("을 벌었습니다.\n");
			printLog("인생게임을 진행하시려면 SPACE를 눌러주세요.");
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
	printLog("(을)를 차렸습니다.\n");

	virualMoney = Random(-30,70)*1000;

	if(virualMoney>0) {
		printLog("가게가 번창해서 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 벌었습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("가게가 잘 안 돼서 본전치기만 했습니다.\n");
	}
	else {
		printLog("가게가 망해서 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 잃었습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void PartTime(void) {

	char sen[100];
	strcpy(sen,partTime[Random(0,PARTTIME_NUMBER-1)].name);
	printLog(sen);
	printLog(" 아르바이트를 했습니다.\n");

	virualMoney = Random(0,70)*100;
	if(strcmp("택배 상하차",sen)==0) virualMoney = -1000;

	if(virualMoney>0) {
		printLog("열심히 일해서 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 벌었습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("실수를 엄청 해서 쫓겨났습니다.\n");
	}
	else if (virualMoney<0) {
		printLog("파스 값으로 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 썼습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Contest(void) {

	printLog(contest[Random(0,CONTEST_NUMBER-1)].name);
	printLog(" 대회에 참가하였습니다.\n");

	virualMoney = Random(-20,50)*1000;

	if(virualMoney>0) {
		printLog("대회에서 우승해서 ");
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 받았습니다.\n");
	}
	else if (virualMoney==0) {
		printLog("아쉽게도 대회에서 탈락하였습니다.\n");
	}
	else {
		printLog("너무 열심히 해서 ");
		printLog(body[Random(0,BODY_NUMBER-1)].name);
		printLog("(을)를 다쳤습니다.\n");
		printLog("치료비로 ");
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 썼습니다.\n");
	}
	player.money+=virualMoney;
	DrawMoneyonBoard();
}

void Beg(void) {

	if(player.money>0) {
		printLog("지하철역 노숙자에게 ");
		virualMoney = Random(-50,-10)*10;
		SetColor(RED); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 주었습니다.\n");
	}
	else {
		printLog("너무 돈이 없어서 지하철 역에서 구걸을 했습니다.\n");
		printLog("통 큰 부자에게 ");
		virualMoney = Random(10,100)*1000;
		SetColor(YELLOW); printLog(MoneywithComma(virualMoney));
		SetColor(WHITE); printLog("을 받았습니다.\n");
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
			printLog("(이)가 최고의 실적을 올렸습니다.\n");
			printLog(company);
			printLog("의 주식이 폭등하였습니다.\n");
			stock[companyNum[i]].price *= (double)Random(120,130)/100;
			printLog("\n");
		}
		else if(virualMoney==0) {
			noNews++;
		}
		else {
			printLog(company);
			printLog("(이)가 최악의 실적을 냈습니다.\n");
			printLog(company);
			printLog("의 주식이 폭락하였습니다.\n");
			stock[companyNum[i]].price *= (double)Random(70,90)/100;
			printLog("\n");
		}
	}

	if(noNews==2) {
		printLog("아직은 아무런 사회 뉴스가 없습니다.");
	}
	DrawMoneyonBoard();

}


void GenerateContents(void) {

	strcpy(contents[0].name,"주식");
	contents[0].function=BuySellStock;
	strcpy(contents[1].name,"부동산");
	contents[1].function=BuySellProperty;
	strcpy(contents[2].name,"지진");
	contents[2].function=Earthquake;
	strcpy(contents[3].name,"불이야");
	contents[3].function=Fire;
	strcpy(contents[4].name,"강도");
	contents[4].function=Robbery;
	strcpy(contents[5].name,"사업");
	contents[5].function=Company;
	strcpy(contents[6].name,"경마");
	contents[6].function=Horse;
	strcpy(contents[7].name,"대공황");
	contents[7].function=Depression;
	strcpy(contents[8].name,"호경기");
	contents[8].function=Prosperity;
	strcpy(contents[9].name,"홀짝게임");
	contents[9].function=oddEvenGame;
	strcpy(contents[10].name,"창업");
	contents[10].function=Store;
	strcpy(contents[11].name,"아르바이트");
	contents[11].function=PartTime;
	strcpy(contents[12].name,"대회참가");
	contents[12].function=Contest;
	strcpy(contents[13].name,"구걸");
	contents[13].function=Beg;
	strcpy(contents[14].name,"사회뉴스");
	contents[14].function=SocialNews;
}

void GenerateWords(void) {
	strcpy(body[0].name,"다리");
	strcpy(body[1].name,"거..거기");
	strcpy(body[2].name,"팔");
	strcpy(body[3].name,"머리");
	strcpy(body[4].name,"아킬레스건");
	strcpy(body[5].name,"뇌");

	strcpy(company[0].name,"건설");
	strcpy(company[1].name,"전자");
	strcpy(company[2].name,"게임");
	strcpy(company[3].name,"부동산");
	strcpy(company[4].name,"마약");
	strcpy(company[5].name,"운송");
	strcpy(company[6].name,"야동");

	strcpy(store[0].name,"게이바");
	strcpy(store[1].name,"미용실");
	strcpy(store[2].name,"치킨집");
	strcpy(store[3].name,"편의점");
	strcpy(store[4].name,"분식집");
	strcpy(store[5].name,"중국집");
	strcpy(store[6].name,"핸드폰 대리점");

	strcpy(partTime[0].name,"게이바");
	strcpy(partTime[1].name,"미용실");
	strcpy(partTime[2].name,"치킨집");
	strcpy(partTime[3].name,"편의점");
	strcpy(partTime[4].name,"분식집");
	strcpy(partTime[5].name,"중국집");
	strcpy(partTime[6].name,"택배 상하차");

	strcpy(contest[0].name,"아무 것도 안하기");
	strcpy(contest[1].name,"치킨 앞에서 오래 참기");
	strcpy(contest[2].name,"목소리로 유리잔 깨트리기");
	strcpy(contest[3].name,"63빌딩 유리창 빨리 닦기");
	strcpy(contest[4].name,"숟가락으로 사람 죽이기");
	strcpy(contest[5].name,"저스틴 또뜨 노래 오래 듣기");
	strcpy(contest[6].name,"대회에서 가장 빨리 탈락하기");
}