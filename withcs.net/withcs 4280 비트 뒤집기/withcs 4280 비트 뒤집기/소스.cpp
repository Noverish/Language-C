#include <stdio.h>

int main() {
	int x_bit[32]={0};
	int x, p, n;
	int i,j;

	scanf("%d %d %d", &x, &p, &n);

	for(i=0;x!=0;i++) {
		x_bit[i]=x%2;
		x/=2;
	}

	i=p;
	j=n;
	for(;i<=p+n-1;i++) {
		if(x_bit[i]==0) x_bit[i]=1;
		else x_bit[i]=0;
	}
	for(j=0;j<32;j++) {
		printf("%d",x_bit[j]);
	}

	return 0;
}