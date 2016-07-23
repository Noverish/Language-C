#include <stdio.h>


int main()
{
    int a,b,c,d;
    scanf("%d",&a);

    for(b=a;b>0;b--)
    {

        for(c=0;c<b;c++)
            printf("*");
        printf("\n");
    }


    return 0;
}
