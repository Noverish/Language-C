#include <stdio.h>

int main() {

	freopen("input.txt","r",stdin);

	long long int height, width, min, answer;
	int i;

	while(1) {
		scanf("%lld %lld",&height,&width);
		if(height==0 && width==0)
			break;
		min=(height < width) ? height : width;

		for(i=2;i<=min;i++) {
			while(1) {
				if((height%i)==0 && (width%i)==0) {
					height/=i;
					width/=i;
				}
				else
					break;
			}
		}
		answer = height*width;

		printf("%lld\n",answer);
	}

	return 0;
}