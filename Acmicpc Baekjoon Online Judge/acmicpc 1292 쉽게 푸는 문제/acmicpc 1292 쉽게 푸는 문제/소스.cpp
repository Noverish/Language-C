#include <stdio.h>

int main() {

	int arr[1001];
	int i=1,j=1;
	int a=1;
	int sum=0;
	int start, end;
	int while_out=0;

	while(while_out==0) {
		for(i=1;i<=j;i++) {
			arr[a]=j;
			a++;
			if(a==1002) {
				while_out=1;
				break;
			}
		}
		j++;
	}

	scanf("%d %d",&start,&end);

	for(;start<=end;start++) sum+=arr[start];

	printf("%d",sum);

	return 0;
}