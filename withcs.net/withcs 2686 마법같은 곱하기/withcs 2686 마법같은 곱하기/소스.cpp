#include <stdio.h>

int main() {

	int test_case;

	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {

		int number[1000];
		int i;
		int k, n;
		int no_number=0;
		
		for(i=0;i<1000;i++) number[i]=0;

		scanf("%d %d",&n, &k);

		number[0]=k;

		for(i=0;1;i++) {
			if(i==990) {
				no_number=1;
				break;
			}
			number[i+1]+=(number[i]*n)%10;
			number[i+2]+=(number[i]*n)/10;
			if(number[i+1]>=10) {
				number[i+1]-=10;
				number[i+2]++;
			}
			if(number[i+2]>=1) {
				continue;
			}
			if(number[i+1]==k) {
				if(number[i]!=0)
					break;
			}
		}

		if(no_number==1) {
			printf("0\n");
			continue;
		}

		for(;i>=0;i--)
			printf("%d",number[i]);
		printf("\n");

	}

	return 0;
}