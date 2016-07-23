#include <stdio.h>

int prime_number[1000];

int square(int a, int b) {
	//a의 b승
	int i;
	int ans=1;

	for(i=0;i<b;i++)
		ans*=a;

	return ans;
}

int find_number_relative_prime(int length_array) {
	
	int i=0,j=0;
	int number_relative_prime=1;
	int now_prime_number;
	int pow_number=0;

	while(i<=length_array) {
		now_prime_number=prime_number[i];

		while(now_prime_number == prime_number[i+j]) {
			pow_number++;
			j++;
		}
		number_relative_prime*= square(prime_number[i],pow_number) - square(prime_number[i],pow_number-1);

		i=i+j;
		j=0;
		pow_number=0;
	}

	printf("%d\n",number_relative_prime);

	return 0;
}

int dividion(int number) { //소인수 분해

	int i;
	int save_number=0;

	for(i=0;i<1000;i++) prime_number[i] = 0;

	while(number != 1) {
		for(i=2;i<=number;i++) {
			if(number%i==0) {
				prime_number[save_number++]=i;
				number/=i;
				break;
			}
		}
	}

	return save_number-1;
}

int main() {

	//freopen("input.txt","r",stdin);

	while(1) {
		int number_main;
		int length_array_main;

		scanf("%d",&number_main);

		if(number_main==0) break;

		length_array_main = dividion(number_main);

		find_number_relative_prime(length_array_main);

	}
	return 0;
}


/*

12와 서로소이면 48과서로소

48=2^4 * 3

48이하의 서로소인수의 갯수는:(2^4-2^3) * (3^1 - 3^0) =8 * 2=16

그리고 49가 서로소이므로 17개

n=p^x* ...q^y (소인수분해)

n과 서로소인 n이하의수의 갯수는 [p^x-p^(x-1)]*...*[q^y-q^(y-1)]

*/