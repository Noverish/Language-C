#include <stdio.h>
#include <math.h>

int S[28];

char find(int number) {
	int i=0;

	for(;i<28;i++)
		if(number<=S[i])
			break;

	if(i==0) {
		if(number==1)
			return 'm';
		else
			return 'o';
	}

	if(number<=S[i-1]+i+3) {
		if(number==S[i-1]+1)
			return 'm';
		else
			return 'o';
	}
	else {
		number=number-(S[i-1]+i+3);
		char ch=find(number);
		return ch;
	}
}

int main() {

	freopen("output.txt","w",stdout);

	int i, number;

	S[0]=3;
	for(i=0;i<28;i++)
		S[i+1]=2*S[i]+i+4;
	
	
	for(i=1;i<9;i++)
		printf("%c",find(pow((double)10,i)));

	return 0;
}