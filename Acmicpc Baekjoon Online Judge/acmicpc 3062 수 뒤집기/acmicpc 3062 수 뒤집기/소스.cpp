#include <stdio.h>
 
int main() {
 
    int test_case;
    int number,digit;
    int i,j;
	int num_to_char[20]={0};
	int copy_num_to_char[20]={0};
 
    scanf("%d",&test_case);//테스트 횟수를 입력받는다.
 
    for(i=0;i<test_case;i++) {//테스트 케이스 만큼 반복시작
        scanf("%d",&number);// 숫자를 입력 받는다.

        for(digit=1;number!=0;digit++) {//숫자를 배열에 한자리씩 입력
            copy_num_to_char[20-digit]=num_to_char[20-digit]=number%10;
            number/=10;
        }

        digit--;//위 대로 하면 자리수가 +1되서 나오므로 1을 뺀다.

        for(j=0;j<digit;j++) {//숫자를 뒤집은 다음에 더한다.
            num_to_char[19-j]+=copy_num_to_char[20-digit+j];
        }

		for(j=0;j<digit;j++) { //한 자리에 10이 넘어가는 것을 계산
            if(num_to_char[19-j]>=10) {
                num_to_char[19-j-1]++;
                num_to_char[19-j]-=10;
            }
        }

        if(num_to_char[19-digit]==1) digit++;//맨 앞자리가 10이 넘어가서 자리수가 늘어난 경우를 체크

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