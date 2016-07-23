#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 2147483647
int find_GCD(int a, int b) {

	int swap, save;
	int k=0;
	int copy_a, copy_b;

	while((a%2==0) && (b%2==0)) {
		a/=2;
		b/=2;
		k++;
	}

	while(a%2==0)
		a/=2;
	while(b%2==0)
		b/=2;

	while(1) {
		if(a<b){
			swap=a;
			a=b;
			b=swap;
		}
		if(a-b==0)
			break;
		a=a-b;
		while(a%2==0)
			a/=2;
	}

	return a*pow(2.0,k);
}

int denominator(char number[], int *boonza, int *boonmo, int rotation) {
	
	int under, up;
	int only_num, GCD;
	int i, k;

	only_num=atoi(number);

	up=only_num-only_num/(int)pow(10.0,rotation);
	under=(pow(10.0,rotation)-1)*pow(10.0,(int)strlen(number)-rotation-1);

	GCD=find_GCD(under,up);
	under/=GCD;
	up/=GCD;

	if(*boonmo > under) {
		*boonmo=under;
		*boonza=up;
	}

	return 0;
}

int main() {

	freopen("input.txt","r",stdin);

	char number[50];
	int boonza, boonmo, under_point, only_num;
	int i;

	while(1) {

		gets(number);
		boonmo=MAX;

		if(strcmp(number,"0")==0)
			break;

		for(i=strlen(number)-1;number[i]=='.';i--)
			number[i]=0;
		under_point=strlen(number)-2;
		strcpy(number+1,number+2);

		for(;under_point>0;under_point--)
			denominator(number,&boonza,&boonmo,under_point);

		printf("%d/%d\n",boonza,boonmo);
		
	}

	return 0;
}