#include <stdio.h>
#include <math.h>

struct restroom123{
	int x;
	int y;
};

struct restroom123 restroom[1000];

double lenght(int num1, int num2) {
	double a=num1;
	double b=num2;

	return sqrt(a*a+b*b);
}

int aabs(int a) {
	if(a>0)
		return a;
	else
		return -a;
}

void find_rest(int x, int y, int restroom_num){
	int i;
	int min=0x7fffffff;
	int len;
	int loc;

	for(i=0;i<restroom_num;i++) {
		len=lenght(restroom[i].x-x,restroom[i].y-y);
		if(min>len) {
			min=len;
			loc=i;
		}
	}

	printf("%d %d\n",restroom[loc].x,restroom[loc].y);
	
}

int main() {

	freopen("input.txt","r",stdin);

	int restroom_num, people_num;
	int x,y;
	int i;

	scanf("%d %d",&restroom_num,&people_num);

	for(i=0;i<restroom_num;i++) 
		scanf("%d %d",&restroom[i].x,&restroom[i].y);

	for(i=0;i<people_num;i++) {
		scanf("%d %d",&x,&y);
		find_rest(x,y,restroom_num);
	}

	return 0;
}