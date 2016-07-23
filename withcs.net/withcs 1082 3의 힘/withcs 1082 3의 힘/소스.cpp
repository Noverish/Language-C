#include <stdio.h>
#include <math.h>
#include <string.h>

char square3[70][35];
int save[70];
int stack_end=0;
int front=0;

void swap(char *a, char *b) {
	char c;
	c=*a;
	*a=*b;
	*b=c;
}

int push(int a) {
	
	save[front++]=a;

	return front-1;
}

long long square2(int b) {

	int i;
	long long ans=1;

	for(i=0;i<b;i++)
		ans*=2;

	return ans;
}

void find(long long n) {

	int i;

	if(n==1)
		return;

	for(i=0;1;i++)
		if( log((double)n)/log((double)2) <= i)
			break;

	stack_end=push(i-1);
	n-=square2(i-1);
	find(n);

}

void fill_square3(void) {

	square3[0][0]=1;

	int i,j;
	int len;

	for(i=0;i<65;i++) {
		for(j=0;j<=34;j++)
			square3[i+1][j]=square3[i][j]*3;
		for(j=0;j<=34;j++)
			if(square3[i+1][j]>=10) {
				square3[i+1][j+1]+=square3[i+1][j]/10;
				square3[i+1][j]%=10;
		}
	}

	for(i=0;i<=65;i++) {
		for(j=34;j>=0 && square3[i][j]==0;j--);
		for(;j>=0;j--)
			square3[i][j]+='0';
	}

	

	for(i=0;i<=65;i++) {
		len=strlen(square3[i]);
		for(j=0;j<len/2;j++)
			swap(&square3[i][j],&square3[i][len-j-1]);
	}

}

int main() {

	freopen("input.txt","r",stdin);

	fill_square3();

	long long n;

	while(1) {
		stack_end=0;
		front=0;

		scanf("%lld",&n);

		if(n==0)
			break;

		find(n);

		int i;
		printf("{");
		if(stack_end!=0)
			for(i=stack_end;i>=0;i--) {
				printf(" %s",square3[save[i]]);
				if(i!=0)
					printf(",");
			}
		printf(" }\n");
	}

	return 0;
}