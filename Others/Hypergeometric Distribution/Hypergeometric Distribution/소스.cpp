#include <stdio.h>
#include <math.h>
#include <string.h>

double hyper(int x, int n, int a, int N) {
	return combi(a,x)*combi(N-a,n-x)/combi(N,n);
}

double binomal(int x, int n, double p) {
	return combi(n,x)*pow((double)p,x)*pow((double)(1-p),n-x);
}

double poisson(int x, double ramda) {
	double e = 2.7182818284;

	double answer = pow(ramda,x)*pow(e,-ramda);
	int i = 1;
	for(int i = 1;i<=x;i++)
	answer/=i;

	return answer;
}

double combi(int n, int r) {
	double answer = 1;
	int i = n, j = 1, k = 1;
	for(;i>=1;i--) {
		answer *= i;
		if(j<=r) {
			answer /= j;
			j++;
		}
		if(k<=n-r) {
			answer /= k;
			k++;
		}
	}
	return answer;
}

int main() {

	printf("전산 수학 2 계산기\n");
	printf("함수 목록\n");
	printf("    b(x;n,p)     B(x;n,p)   \n");
	printf("    h(x;n,a,N)   H(x;n,a,N) \n");
	printf("    f(x;rambda)  F(x;rambda)\n");
	printf("명령어 사용방법\n");
	printf("    b 2 5 0.8\n");
	printf("    b 2~3 5 0.8\n");
	printf("    b 2~ 5 0.8\n");

	while(true) {

		int x, n, a, N;
		double p, ramda;
		char ch;
		char sen[5];
		double answer = 0;
		
		ch = getchar();

		getchar();

		scanf("%s",sen);

		if(strlen(sen) == 1) {
			

			if(ch == 'b') {
				scanf("%d %lf", &n, &p);
				answer = binomal(x,n,p);
			}
			else if(ch == 'B') {
				scanf("%d %lf", &n, &p);
				int originX = x;
				for(x = 0 ; x <= originX ; x++)
					answer += binomal(x,n,p);
			}
			else if(ch=='h') {
				scanf("%d %d %d", &n, &a, &N);
				answer = hyper(x,n,a,N);
			}
			else if(ch=='H') {
				scanf("%d %d %d", &n, &a, &N);
				int originX = x;
				for(x = 0 ; x <= originX ; x++)
					answer += hyper(x,n,a,N);
			}
			else if(ch == 'f') {
				scanf("%lf", &ramda);
				answer = poisson(x, ramda);
			}
			else if(ch == 'F') {
				scanf("%lf", &ramda);
				int originX = x;
				for(x = 0 ; x <= originX ; x++)
					answer += poisson(x,ramda);
			}
		}
		else if(strlen(sen) == 2) {

		}

		getchar();

		printf("%lf\n",answer);
	}
	return 0;
}