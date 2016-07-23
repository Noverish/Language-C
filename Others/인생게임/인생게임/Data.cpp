#include "essential.h"

Board contents[50];
Asset stock[STOCK_NUMBER];
Asset property[PROPERTY_NUMBER];

char number[30];

void ResetStockData(void) {

	FILE * fp = fopen("StockData.bin","wb");

	strcpy(stock[0].name,"SamSeong");
	stock[0].price = (long long)Random(90,110);
	strcpy(stock[1].name,"Gougle");
	stock[1].price = (long long)Random(90,110)*2;
	strcpy(stock[2].name,"Appie");
	stock[2].price = (long long)Random(90,110)*5;
	strcpy(stock[3].name,"Facedook");
	stock[3].price = (long long)Random(900,1100);
	strcpy(stock[4].name,"Mircosoft");
	stock[4].price = (long long)Random(900,1100)*2;
	strcpy(stock[5].name,"1BM");
	stock[5].price = (long long)Random(900,1100)*5;

	fwrite((void*)stock,sizeof(stock),1,fp);

	fclose(fp);
}

void ResetPropertyData(void) {

	FILE * fp = fopen("PropertyData.bin","wb");

	strcpy(property[0].name,"����ü����");
	property[0].price = Random(900,1100)*(long long)500;
	strcpy(property[1].name,"�����û");
	property[1].price = Random(900,1100)*(long long)1000;
	strcpy(property[2].name,"�ڿ���");
	property[2].price = Random(900,1100)*(long long)2000;
	strcpy(property[3].name,"63����");
	property[3].price = Random(900,1100)*(long long)5000;
	strcpy(property[4].name,"����Ÿ��");
	property[4].price = Random(900,1100)*(long long)10000;
	strcpy(property[5].name,"û�ʹ�");
	property[5].price = Random(900,1100)*(long long)20000;
	strcpy(property[6].name,"��Ÿ��");
	property[6].price = Random(900,1100)*(long long)50000;
	strcpy(property[7].name,"�ݷμ���");
	property[7].price = Random(900,1100)*(long long)100000;
	strcpy(property[8].name,"�����强");
	property[8].price = Random(900,1100)*(long long)200000;
	strcpy(property[9].name,"����ž");
	property[9].price = Random(900,1100)*(long long)500000;
	strcpy(property[10].name,"�Ƕ�̵�");
	property[10].price = Random(900,1100)*(long long)1000000;

	fwrite((void*)property,sizeof(property),1,fp);

	fclose(fp);
}

void ResetPlayerData(void) {
	int i,j;

	FILE * fp = fopen("PlayerData.bin","wb");

	for(i=0;i<9;i++)
		player.board[i]=Random(0,CONTENTS_NUMBER-1);
	player.money=5000;
	player.turns=0;
	player.gold=0;
	for(i=0;i<20;i++) 
		for(j=0;j<4;j++) 
			player.stock[i][j]=player.property[i][j]=0;

	fwrite((void*)&player,sizeof(player),1,fp);

	fclose(fp);
}

void RoadStockData(void) {
	FILE * fp = fopen("StockData.bin","rb");
	if(fp==NULL) {
		ResetStockData();

		printLog("�ֽ� ���� �����Ͱ� �����Ǿ��־����ϴ�.\n");
		printLog("�ֽ� ������ �ʱ�ȭ �˴ϴ�.\n");
	}
	else {
		fread((void*)stock,sizeof(stock),1,fp);
		fclose(fp);
	}
}

void RoadPropertyData(void) {
	FILE * fp = fopen("PropertyData.bin","rb");
	if(fp==NULL) {
		ResetPropertyData();

		printLog("�ε��� ���� �����Ͱ� �����Ǿ��־����ϴ�.\n");
		printLog("�ε��� ������ �ʱ�ȭ �˴ϴ�.\n");
	}
	else {
		fread((void*)property,sizeof(property),1,fp);
		fclose(fp);
	}
}

void RoadPlayerData(void) {
	FILE * fp = fopen("PlayerData.bin","rb");

	if(fp==NULL) {
		ResetPlayerData();

		printLog("���� Player �����Ͱ� �����Ǿ��־����ϴ�.\n");
		printLog("Player �����Ͱ� �ʱ�ȭ �˴ϴ�.\n");
	}
	else {
		fread((void*)&player,sizeof(player),1,fp);
		fclose(fp);
	}
}

void SaveData(void) {
 	FILE * fp = fopen("PlayerData.bin","wb");
	fwrite((void*)&player,sizeof(player),1,fp);
	fclose(fp);

	fp = fopen("PropertyData.bin","wb");
	fwrite((void*)&property,sizeof(property),1,fp);
	fclose(fp);

	fp = fopen("StockData.bin","wb");
	fwrite((void*)&stock,sizeof(stock),1,fp);
	fclose(fp);
}

void RoadData(void) {
	GenerateContents();
	GenerateWords();
	RoadPlayerData();
	RoadStockData();
	RoadPropertyData();
}