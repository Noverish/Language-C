#include <stdio.h>

int main() {
	int x_bit[32]={0};
	int x, n;
	int i,j;

	scanf("%d %d", &x, &n);

	for(i=0;x!=0;i++) {
		x_bit[i]=x%2;
		x/=2;
	}
	if(n>=0) {
		j=n%32;
		for(;j<32;j++) {
			printf("%d",x_bit[j]);
		}
		for(j=0;j<n%32;j++) {
			printf("%d",x_bit[j]);
		}
	}

/*	else {
		n*=-1;
		j=n%32;
		for(;j>0;j--) {
			printf("%d",x_bit[32-j]);  //n이 음수일때를 생각했다.
		}
		for(j=0;j<32-(n%32);j++) {
			printf("%d",x_bit[j]);
		}
	}*/

	return 0;
}