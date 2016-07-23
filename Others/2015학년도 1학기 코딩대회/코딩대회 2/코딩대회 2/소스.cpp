#include <stdio.h>

int main() {
	
	freopen("input.txt","r",stdin);

	int ch;
	int number;
	int sum;
	int index[100000];
	int i=0, j;

	while(1) {
		sum=0;
		while(1) {
			scanf("%d",&number);
			ch=getchar();
			sum+=number;

			if(ch=='\n' || ch==EOF)
				break;
		}

		for(j=0;j<i;j++)
			if(index[j]==sum)
				break;
		if(j==i)
			index[i++]=sum;

		if(ch==EOF)
			break;
	}

	printf("%d",i);

	return 0;
}