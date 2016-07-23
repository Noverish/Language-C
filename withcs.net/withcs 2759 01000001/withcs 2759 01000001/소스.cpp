#include <stdio.h>
#include <string.h>
#define LENGTH 100

/*���� 1�� 0�� �ƽ�Ű�ڵ��� 1�� 0���� �ٲ۴�*/
int change_number_to_ASCII(char real_number[]) {
	int i;

	for(i=LENGTH-1;i>=0;i--) 
		if(real_number[i]==1) break;

	if(i==-1) { //0�϶��� ����
		real_number[0] += '0';
		return 0;
	}

	for(;i>=0;i--)
		real_number[i] += '0';

	return 0;
}

/*�ƽ�Ű�ڵ��� 1�� 0�� ���� 1�� 0���� �ٲ۴�*/
int change_ASCII_to_number(char ASCII_number[]) {

	int i;

	for(i=0;i<LENGTH;i++) 
		if(ASCII_number[i]!=0) 
			ASCII_number[i]-='0';

	return 0;
}

/*���ڿ��� �����´�*/
int reverse_array(char number_array[]) {

	int array_length;
	int trash;
	int i;

	array_length = strlen(number_array)-1;

	for(i=0;i< (array_length+1)/2;i++) {
		trash = number_array[i];
		number_array[i] = number_array[array_length-i];
		number_array[array_length-i] = trash;
	}

	return 0;
}

int sum(char two_number1_array[], char two_number2_array[], char sum_number_array[]) {
	
	int i;

	reverse_array(two_number1_array);//���ڿ��� ������
	reverse_array(two_number2_array);

	change_ASCII_to_number(two_number1_array);//���� 0�� 1�� �ٲ۵�
	change_ASCII_to_number(two_number2_array);

	for(i=0;i<LENGTH;i++) {//�ϴ� ���ϰ�
		sum_number_array[i] += two_number1_array[i] + two_number2_array[i];
		if(sum_number_array[i] >= 2) {
			sum_number_array[i]-=2;
			sum_number_array[i+1]++;
		}
	}
	change_number_to_ASCII(sum_number_array);//sum ���ڿ��� ���� 0�� 1�� �ƽ�Ű�ڵ��� 0�� 1�� �ٲ۴�

	reverse_array(sum_number_array);//sum ���ڿ��� �����´�

	return 0;
}

int main() {

	freopen("input.txt","r",stdin);

	char two_number1[100], two_number2[100], sum_number[100];
	int test_case;
	int i,j;

	scanf("%d",&test_case);

	for(i=1;i<=test_case;i++) {

		for(j=0;j<100;j++) //�迭 �ʱ�ȭ
			sum_number[j] = two_number1[j] = two_number2[j] = NULL;

		scanf("%s %s",two_number1,two_number2);

		sum(two_number1,two_number2,sum_number);

		printf("%d %s\n",i,sum_number);
	}
	return 0;
}
