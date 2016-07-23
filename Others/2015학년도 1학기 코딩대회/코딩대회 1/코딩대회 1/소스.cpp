#include <stdio.h>

struct asdf {
	int num1;
	int num2;
	int num3;
};

struct asdf three[10000];

int main() {

	freopen("input.txt","r",stdin);

	int number;
	int process;
	int a, b, c;
	int i=0;
	int kind_num;

	scanf("%d",&number);

	for(;number>0;number--) {
		scanf("%d",&process);

		if(process<=6) {
			printf("NULL\n");
			continue;
		}

		for(a=1;a<=process-2;a++) {
			for(b=a+1;b<=process-a-2;b++) {
				c=process-a-b;
				if(c == a || c == b)
					continue;
				if(b>c)
					break;

				three[i].num1=a;
				three[i].num2=b;
				three[i].num3=c;
				i++;
			}
		}

		kind_num=i;

		for(i=0;i<kind_num;i++)
			printf("%d %d %d\n",three[i].num1,three[i].num2,three[i].num3);

		i=0;

	}

	return 0;
}