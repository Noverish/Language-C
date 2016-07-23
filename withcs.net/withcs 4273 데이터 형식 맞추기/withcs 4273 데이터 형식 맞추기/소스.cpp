#include <stdio.h>
#include <math.h>

int main() {

	//freopen("input.txt","r",stdin);

	int ch=0;
	
	long long number=0;
	int i;
	int digit;
	int end=1;


	while(1) {

		char num[50]={0};
		end=0;
		number=0;
		
		gets(num);

		if(num[0]==0) break;

		for(i=0;1;i++) {
			if(num[i]==0) break;
		}

		
		digit=i-1; // i는 \n뒤의 0까지 셌으므로 digit은 i에서 1을 뺀다

		for(i=0;1;i++) {
			/*문자로 받은 숫자를 실제 숫자로 변경*/
			if('0'<=num[i] && num[i]<='9')
				num[i]-='0';
			if(i==digit) break;
		}
		

		if(num[0]=='-') { // 음수일때 생각
			digit--;//-는 숫자가 아니므로 digit에서 1을 뺀다.

			if(digit>10) {
				printf("signed int64\n");
				continue;
			}

			for(i=1;digit>=0;i++) {  //0번째에는 '-'가 들어가 있으므로 1부터 시작
				number+=num[i]*pow((double)10,(double)digit);
				digit--;
			}
			number*=-1;
		}
		else {            //양수 일때

			if(digit>10) {
				printf("unsigned int64\n");
				continue;
			}

			for(i=0;digit>=0;i++) {
				number+=num[i]*pow((double)10,(double)digit);
				digit--;
			}
		}


		
		if(-pow(  (double)2,(double)63  ) <= number && number <= -1 -pow(  (double)2,(double)31)  )   
			printf("signed int64\n");
		if(-pow(  (double)2,(double)31  ) <= number && number <= -1 -pow(  (double)2,(double)15 )  )   
			printf("signed long\n");
		if(-pow(  (double)2,(double)15  ) <= number && number <= -1 -pow(  (double)2,(double)7 )  )   
			printf("signed short\n");
		if(-pow(  (double)2,(double)7   ) <= number && number <= -1)                                  
			printf("signed byte\n");
		if(              0                <= number && number <= pow(  (double)2,(double)8   )-1)     
			printf("unsigned byte\n");
		if( pow(  (double)2,(double)8   ) <= number && number <= pow(  (double)2,(double)16  )-1)     
			printf("unsigned short\n");
		if( pow(  (double)2,(double)16  ) <= number && number <= pow(  (double)2,(double)32  )-1)     
			printf("unsigned long\n");
		if( pow(  (double)2,(double)32  ) <= number && number <= pow(  (double)2,(double)64  )-1)     
			printf("unsigned int64\n");

		if(end==-1) break;
	}
	return 0;
}