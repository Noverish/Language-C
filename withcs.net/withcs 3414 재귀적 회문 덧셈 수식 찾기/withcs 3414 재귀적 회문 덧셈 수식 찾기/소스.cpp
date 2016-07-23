#include <stdio.h> 

int number_table[1500][1500];

int fill_table(void) {

	int i;
	int n,p;

	for(i=0;i<1500;i++) number_table[i][1]=1;

	number_table[2][2]=1;

	for(n=3;n<1500;n++) {
		for(p=2;p<=n;p++) {

			if(n%2==1 && p%2==1) {
				for(i=1;i<n;i+=2) {
					number_table[n][p] += number_table[(n-i)/2][(p-1)/2];
				}
			}
			else if(n%2==0 && p%2==1) {
				for(i=2;i<n;i+=2) {
					number_table[n][p] += number_table[(n-i)/2][(p-1)/2];
				}
			}
			else if(n%2==0 && p%2==0) {
				number_table[n][p] = number_table[n/2][p/2];
			}

		}
	}

	return 0;
}

int find_equation(int n, int p) {

	int i,j;
	int return_number=0;

	if(n<p) return 0;
	else if(n%2==1 && p%2==0) return 0;
	else if(n==p) return 1;
	else if(p==1) return 1;
	else if(n==1 || n==2) return 1;

	if(n%2==1 && p%2==1) {
		for(i=1;i<n;i+=2) {
			return_number += find_equation((n-i)/2, (p-1)/2);
		}
		return return_number;
	}
	else if(n%2==0 && p%2==1) {
		for(i=2;i<n;i+=2) {
			return_number += find_equation((n-i)/2, (p-1)/2);
		}
		return return_number;
	}
	else if(n%2==0 && p%2==0) {
		return_number = find_equation(n/2, p/2);
		return return_number;
	}

	return return_number;
}

int main() {

	//freopen("input.txt","r",stdin);

	int test_case, times;
	int question_number;
	int i;
	long long answer=0;

	fill_table();

	scanf("%d",&test_case);

	for(times=1;times<=test_case;times++) {
		scanf("%d",&question_number);

		for(i=1;i<=question_number;i++)
			answer += number_table[question_number][i];

		printf("%d %lld\n",times,answer);

		answer=0;
	}

	return 0;
}