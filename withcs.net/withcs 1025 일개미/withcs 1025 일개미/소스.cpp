#include <stdio.h>
#include <math.h>
#define NUMBER_LENGHT 10000

char ant_num[NUMBER_LENGHT];

int multiplication(int number) {
	
	int order = 0;
	int i, answer, origin_number;
	origin_number=number;

	for(;1;order++) {
		while((ant_num[order]%10)!=1) {
			number=origin_number;
			for(i=0;number>0;i++) {
				ant_num[i+order] += number%10;
				number/=10;
			}
		}
		for(i=0;i<7;i++) {
			if(ant_num[i+order]>=10) {
				ant_num[i+order+1]+=ant_num[i+order]/10;
				ant_num[i+order]%=10;
			}
		}
		/* check that are all number 1? */
		for(i=order+5;ant_num[i]==0 && i>=0;i--); // find biggest digit
		answer=i+1;
		for(;i>=order && i>=0;i--)
			if(ant_num[i]!=1)
				break;
		if(i==order-1) {
			for(i=0;i<=answer;i++)
				ant_num[i]=0;
			return answer;
		}
	}
}

int main() {

	freopen("input.txt","r",stdin);

	int i;
	int number;

	while(scanf("%d",&number)!=EOF) {
		
		printf("%d\n",multiplication(number));

	}

	return 0;
}