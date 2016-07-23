#include <stdio.h>

int main() {
	int x_bit[32]={0}, y_bit[32]={0};
	int x, y, p, n;
	int i,j;

	scanf("%d %d %d %d", &x, &y, &p, &n);

	for(i=0;x!=0;i++) {
		x_bit[i]=x%2;
		x/=2;
	}
	for(i=0;y!=0;i++) {
		y_bit[i]=y%2;
		y/=2;
	}
	j=n;
	i=p;
	for(;p<=i+n-1;p++) {
		x_bit[p]=y_bit[32-j];
		j--;
	}
	for(j=0;j<32;j++) {
		printf("%d",x_bit[j]);
	}

	return 0;
}