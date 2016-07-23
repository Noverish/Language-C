#include <stdio.h>

int uclid(int num1, int num2) {
	
	int i;
	int swap;
	int division;

	for(i=1;;i++) {
		if(num1>num2) {
			swap=num1;
			num1=num2;
			num2=swap;
		}
		division = num2/num1;
		if(division>1)
			return i;
		num2-=num1*division;
		if(num2==0)
			return i;
	}

}

int main() {
	
	int num1, num2;
	int answer;

	while(1) {
		scanf("%d %d",&num1,&num2);
		
		if(num1==0 && num2==0)
			break;

		answer=uclid(num1, num2);

		if(answer%2==1)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}

	return 0;
}