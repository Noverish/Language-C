#include <stdio.h>

long pactorial(int n, int r) {
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
	int a,b;
	while(1) {

		scanf("%d %d",&a,&b);
		if((b==-1)&&(a==-1))
			break;

		if((a+b)==pactorial(a+b,b))
			printf("%d+%d=%d\n",a,b,a+b);
		else
			printf("%d+%d!=%d\n",a,b,a+b);

	}
	return 0;
}