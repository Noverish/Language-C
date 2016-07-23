#include <stdio.h>

int main() {
	
	int Time;
	int A=0, B=0, C=0; //A는 5분 B는 1분 C는 10초

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
