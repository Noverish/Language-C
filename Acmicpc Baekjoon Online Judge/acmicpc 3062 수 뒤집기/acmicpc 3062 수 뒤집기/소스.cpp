#include <stdio.h>
 
int main() {
 
    int test_case;
    int number,digit;
    int i,j;
	int num_to_char[20]={0};
	int copy_num_to_char[20]={0};
 
    scanf("%d",&test_case);//�׽�Ʈ Ƚ���� �Է¹޴´�.
 
    for(i=0;i<test_case;i++) {//�׽�Ʈ ���̽� ��ŭ �ݺ�����
        scanf("%d",&number);// ���ڸ� �Է� �޴´�.

        for(digit=1;number!=0;digit++) {//���ڸ� �迭�� ���ڸ��� �Է�
            copy_num_to_char[20-digit]=num_to_char[20-digit]=number%10;
            number/=10;
        }

        digit--;//�� ��� �ϸ� �ڸ����� +1�Ǽ� �����Ƿ� 1�� ����.

        for(j=0;j<digit;j++) {//���ڸ� ������ ������ ���Ѵ�.
            num_to_char[19-j]+=copy_num_to_char[20-digit+j];
        }

		for(j=0;j<digit;j++) { //�� �ڸ��� 10�� �Ѿ�� ���� ���
            if(num_to_char[19-j]>=10) {
                num_to_char[19-j-1]++;
                num_to_char[19-j]-=10;
            }
        }

        if(num_to_char[19-digit]==1) digit++;//�� ���ڸ��� 10�� �Ѿ�� �ڸ����� �þ ��츦 üũ

        for(j=0;j<digit;j++) {
            if(num_to_char[19-j]!=num_to_char[20-digit+j]) {
                printf("NO\n");
                break;
            }
        }

        if(j==digit) printf("YES\n");
    }
    return 0;
}