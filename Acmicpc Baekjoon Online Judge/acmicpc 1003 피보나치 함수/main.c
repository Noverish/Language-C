#include <stdio.h>

int main()
{
    int num0[100], num1[100];
    int test_num;
    int a,c;

    scanf("%d",&test_num);


    for(a=0;a<test_num;a++)
    {
        num0[a]=0, num1[a]=0;

        scanf("%d",&c);

        int fibonacci(int n)
        {
            if (n==0) {

                num0[a]++;
                return 0;
            } else if (n==1) {

                num1[a]++;
                return 1;
            } else {
                return fibonacci(n-1) + fibonacci(n-2);
            }
        }

        int b;
        b=fibonacci(c);
    }


    for(a=0;a<test_num;a++)
    {
        printf("%d %d\n",num0[a],num1[a]);
    }
    return 0;
}
