#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265

int main() {
	//freopen("input.txt","r",stdin);

	while(1) {
		char sen[50];
		int number1, number2;
		double answer, center;

		if(scanf("%s",sen)==EOF)
			break;

		if(strcmp(sen,"sin")==0) {
			scanf("%d",&number1);
			center=number1*PI/180;
			answer=sin((double)center);
			printf("%lf",answer);
		}
		else if(strcmp(sen,"pow")==0) {
			scanf("%d %d",&number1,&number2);
			answer=pow((double)number1,(double)number2);
			printf("%lf",answer);
		}
		else if(strcmp(sen,"exp")==0) {
			scanf("%d",&number1);
			answer=exp((double)number1);
			printf("%lf",answer);
		}
		else {
			while(1);
		}

		printf("\n");

	}
	return 0;
}