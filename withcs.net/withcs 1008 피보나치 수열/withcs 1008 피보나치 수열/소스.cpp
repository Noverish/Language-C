#include <stdio.h>
#include <string.h>


char answer_n_2[1001], answer_n_1[1001], answer_n[1001];

int fibonacci(int n) {
    
	int fibo_number = 3;
	int i,j;

	answer_n_2[0] = answer_n_1[0] = 1;

	for(;;fibo_number++) {
		for(i=0;i<1001;i++) answer_n[i]=0;
		for(i=0;i<1001;i++) {
			answer_n[i]+=answer_n_1[i]+answer_n_2[i];
			
			if(answer_n[i]>=10) {
				answer_n[i+1]++;
				answer_n[i]-=10;
			}
		}

		if(fibo_number==n) return 0;

		for(i=0;i<1001;i++) answer_n_2[i] = answer_n_1[i];
		for(i=0;i<1001;i++) answer_n_1[i] = answer_n[i];

		int a;
	}

}

int main()
{
	freopen("output.txt", "w", stdout);


    int number;
    int i,j;

    scanf("%d",&number);
    
	fibonacci(number);

	for(i=1001;i>=0;i--) if(answer_n[i]!=0) break;

	for(;i>=0;i--) printf("%c",answer_n[i]+'0');

    return 0;

}