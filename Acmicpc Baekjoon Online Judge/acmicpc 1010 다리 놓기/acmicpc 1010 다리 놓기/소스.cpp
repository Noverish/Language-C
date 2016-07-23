#include <stdio.h>
long pactorial(int r, int n) {
	if(r==n) return 1;
	double sum=1;
	int x=n-r;
	for(;n>1;n--) {
		sum*=n;
		sum/=r;
		sum/=x;
		if(r!=1) r--;
		if(x!=1) x--;
	}
	sum+=0.1;
	return sum;
}


int main() {
	int test_case;

	scanf("%d",&test_case);
	
	int n,r; //nCrÀÇ ±× n,r
	for(;test_case>0;test_case--) {

		scanf("%d %d",&r,&n);

		printf("%d\n",pactorial(r,n));

	}
	return 0;
}