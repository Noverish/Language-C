#include <stdio.h>
#include <math.h>

int main() {

	int test_case;
	char ch;
	int i;
	int testIndex;
	int digit;
	int ans=0;
	int print_null=0;


	scanf("%d",&test_case);//test_case 를 입력 받는다
	ch=getchar();//test_case를 입력받을때 누르는 엔터를 받기위해 만듬
	

	for(testIndex = 0;testIndex<test_case;testIndex++) {

		
		char number[20];
		print_null=0;
		ans=0;

		scanf("%s", number);

		/*for(i=0;true;i++) {
			ch=getchar();
			number[i]=ch;
			if(ch=='\n') break;
		}*/
		digit=i-3;

		for(i=0;1;i++) if(number[i]==0) break;

		//printf("NUMBER : %s\n",number);

		if((number[0]=='0'&&number[1]=='x') || (number[0]=='0'&&number[1]=='X')) { //앞에 0x 또는 0X 일때
			for(ch=2;ch<i;ch++) {
				switch (number[ch])
				{
				case 'a': 
				case 'A': {
					number[ch]='9'+1;
					break;
						  }
				case 'b': 
				case 'B': {
					number[ch]='9'+2;
					break;
						  }
				case 'c': 
				case 'C': {
					number[ch]='9'+3;
					break;
						  }
				case 'd':
				case 'D': {
					number[ch]='9'+4;
					break;
						  }
				case 'e':
				case 'E': {
					number[ch]='9'+5;
					break;
						  }
				case 'f':
				case 'F': {
					number[ch]='9'+6;
					break;
						  }
				case '0' : case '1' : case '2' : case '3' : case '4' : case '5' : case '6' : case '7' : case '8' : case '9' : break;
				default : {
					print_null=1;
					break;
						  }
				}
				if(print_null==1) break;

				int nothing;
				nothing =  (int)  pow(  (double)16,  (double)digit  );
				ans+=(number[ch]-'0') * nothing;
				digit--;
			}
			//printf("%d",print_null);
			if(print_null==0) printf("%d\n",ans);
			else printf("null\n");
		}
		else printf("null\n");
	}
	return 0;
}
