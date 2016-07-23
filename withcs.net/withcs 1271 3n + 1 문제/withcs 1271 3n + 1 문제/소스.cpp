#include <stdio.h>
#include <string.h>

int square(int a, int b) {
	int i;
	int number=1;
	
	for(i=0;i<b;i++) {
		number*=a;
	}

	return number;
}

int text_to_number(char A[]) {

	int i;
	int decimal = strlen(A)-1;
	int number=0;

	for(i=0;i<=decimal;i++) {
		number+=(A[i]-'0')*square(10,decimal);
		decimal--;
	}
	return number;
}

int main() {

	freopen("input.txt","r",stdin);
	int number1, number2, ori_number1, ori_number2;;

	while(scanf("%d %d",&number1,&number2)!=EOF) {

		ori_number1=number1;
		ori_number2=number2;

		if(number1>number2) {
			ori_number1=number1;
			number1=number2;
			number2=ori_number1;
		}

		int while_out=0;
		int max=0;
		
		for(;number1<=number2;number1++) {
			int oobak=number1;
			int test_case=1;

			while(oobak!=1) {
				if(oobak%2==1) 
					oobak=3*oobak+1;
				else 
					oobak/=2;
				test_case++;
			}

			max = (max>test_case) ? max : test_case; 
		}

		printf("%d %d %d\n",ori_number1,ori_number2,max);
	}
	return 0;
}