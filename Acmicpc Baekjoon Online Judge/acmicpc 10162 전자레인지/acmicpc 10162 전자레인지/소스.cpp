#include <stdio.h>

int main() {
	
	int Time;
	int A=0, B=0, C=0; //A�� 5�� B�� 1�� C�� 10��

	scanf("%d",&Time);

	if(Time%10!=0) {
		printf("-1");
		return 0;
	}

	for(;Time>=300;Time-=300) A++;
	for(;Time>=60;Time-=60) B++;
	for(;Time>=10;Time-=10) C++;

	printf("%d %d %d",A, B,C);


	

	return 0;
}
