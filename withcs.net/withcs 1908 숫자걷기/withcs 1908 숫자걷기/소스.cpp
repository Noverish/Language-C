#include <stdio.h>

int find_foot(int x, int y) {
	if(x%2==0) {
		if(y==x)
			return 2*x;
		else if(x-y==2)
			return 2*x-2;
		else
			return -1;
	}
	else {
		if(y==x)
			return 2*(x-1)+1;
		else if(x-y==2)
			return 2*(x-1)-1;
		else return -1;
	}
}

int main() {

	int x,y;
	int test_case;

	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {

		scanf("%d %d",&x,&y);

		if(x<0 || y<0) {
			printf("No Number\n");
			continue;
		}

		int foot=find_foot(x,y);

		if(foot==-1)
			printf("No Number\n");
		else
			printf("%d\n",foot);
	}
	return 0;
}