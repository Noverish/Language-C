#include <stdio.h>
#include <string.h>

int main() {

	freopen("input.txt","r",stdin);

	char odd_even[5];
	int n0, n1, n2, n3, n4;
	int i;

	for(i=1;1;i++) {
		scanf("%d",&n0);
		if(n0==0)
			break;
		n1=3*n0;
		if(n1%2==0) {
			n2=n1/2;
			strcpy(odd_even,"even");
		}
		else {
			n2=(n1+1)/2;
			strcpy(odd_even,"odd");
		}
		n3=3*n2;
		n4=n3/9;
		printf("%d. %s %d\n",i,odd_even,n4);
	}

	return 0;
}