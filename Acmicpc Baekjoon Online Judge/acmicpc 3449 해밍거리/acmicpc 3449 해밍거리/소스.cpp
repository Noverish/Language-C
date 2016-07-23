#include <stdio.h>

int main() {

	int test_case;
	int hamming;
	int i;
	int digit;
	int ch;

	scanf("%d",&test_case);
	ch=getchar();

	for(;test_case>0;test_case--) {

		hamming=0;
		digit=0;
		int number1[100]={0}, number2[100]={0};

		for(i=0;1;i++) {
			ch=getchar();
			number1[i]=ch;
			if(number1[i]=='\n') break;
		}
		digit=i;

		for(i=0;1;i++) {
			ch=getchar();
			number2[i]=ch;
			if(number2[i]=='\n') break;
		}

		for(i=0;i<digit;i++) {
			if(number1[i]!=number2[i]) hamming++;
		}

		printf("Hamming distance is %d.\n",hamming);
	}
	return 0;
}