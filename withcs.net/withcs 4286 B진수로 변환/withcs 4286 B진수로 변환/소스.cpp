#include <stdio.h>

int main() {

	int test_case, digit, number;
	int i,j;

	scanf("%d %d",&test_case,&digit);

	for(;test_case>0;test_case--) {
		char answer[20]={0};
		scanf("%d",&number);
		for(i=0;1;i++) {
			answer[i] = number%digit;
			if(0<=answer[i] && answer[i]<=9) {
				answer[i]+='0';
			}
			else {
				answer[i]-=10;
				answer[i]+='A';
			}
			number/=digit;
			if(number==0) break;
		}
		for(;i>=0;i--) printf("%c",answer[i]);
		printf("\n");
	}



	return 0;
}