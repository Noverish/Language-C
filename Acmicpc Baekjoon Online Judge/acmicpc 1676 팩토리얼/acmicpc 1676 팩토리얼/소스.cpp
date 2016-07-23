#include <stdio.h>

long pactorial(int a) {
	long sum=1;
	for(;a>0;a--) {
		sum*=a;
	}
	return sum;
}



int main(){

	int N;
	long number;
	scanf("%d",&N);

	number=pactorial(N);

	return 0;

}