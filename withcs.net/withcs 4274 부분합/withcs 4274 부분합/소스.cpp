#include <stdio.h>

int main() {

	int num, max, sum;
	int t;

	scanf("%d",&num);

	max=sum=0;
	while(num--) {
		scanf("%d",&t);
		sum+=t;
		if(sum<0) sum=0;
		else if(sum>max) max=sum;


	}
	printf("%d",max);

	return 0;
}