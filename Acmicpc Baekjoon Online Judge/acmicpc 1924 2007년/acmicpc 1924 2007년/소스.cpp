#include <stdio.h>


int month, day;

int cal_date(int i, int d) {
	int day_num=0;
	for(i=1;i<=month;i++) {

		switch (i)
		{
		case 1 :
		case 3 :
		case 5 :
		case 7 :
		case 8 :
		case 10 :
		case 12 : {
			for(d=1;d<=31;d++) {
				
				if(i==month&&d==day) {
				 return day_num;
				}
				day_num++;
			}
			break;
				  }
		case 4 :
		case 6 :
		case 9 :
		case 11 : {
			for(d=1;d<=30;d++) {
				
				if(i==month&&d==day) {
				 return day_num;
				}
				day_num++;
			}
			break;
				  }
		case 2 : {
			for(d=1;d<=28;d++) {
				
				if(i==month&&d==day) {
				 return day_num;
				}
				day_num++;
			}
			break;
				 }
		}
	}
}



int main() {

	scanf("%d %d",&month, &day);
	int date;
	
	date=cal_date(month,day)%7;

	switch (date)
	{
	case 1 : {
		printf("TUE");
		break;
	}
	case 2 : {
		printf("WED");
		break;
	}
	case 3 : {
		printf("THU");
		break;
	}
	case 4 : {
		printf("FRI");
		break;
	}
	case 5 : {
		printf("SAT");
		break;
	}
	case 6 : {
		printf("SUN");
		break;
	}
	case 0 : {
		printf("MON");
		break;
	}

	}
	return 0;

}