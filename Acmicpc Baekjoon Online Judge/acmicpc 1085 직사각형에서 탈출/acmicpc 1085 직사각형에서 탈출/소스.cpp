#include <stdio.h>

int main() {

	int x=0, y=0, w=0, h=0;
	int min_len;
	
	scanf("%d %d %d %d",&x, &y, &w, &h);

	min_len=x;

	if(min_len>y) min_len=y;
	if(min_len>h-y) min_len=h-y;
	if(min_len>w-x) min_len=w-x;

	printf("%d",min_len);
	return 0;
}