#include <stdio.h>

double card_number[400];

void filling(void){

	int i;

	for(i=2;i<=400;i++) {
		card_number[i-1]=(1/(double)i)+card_number[i-2];
	}
}

int index(double n) {

	if(n>5)
		return 220;
	else if(n>4)
		return 80;
	else if(n>3)
		return 25;
	else if(n>2)
		return 7;
	else if(n>1)
		return 0;

	return 0;
}

int main() {

	//freopen("input.txt","r",stdin);

	filling();

	while(1) {
		int i, number_index;
		double number=0, want_lenght;

		scanf("%Lf",&want_lenght);

		if(want_lenght==0.0)
			break;

		number_index = index(want_lenght);

		for(i=number_index;i<400;i++)
			if(card_number[i] >= want_lenght)
				break;

		printf("%d card(s)\n",i);
	}
	return 0;
}