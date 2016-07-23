#include <stdio.h>


int main()
{
    int a,b,c,d;
    scanf("%d",&a);

    for(b=0;b<a;b++)
    {
        for(c=a;c>b+1;c--)
            printf(" ");
        for(c=0;c<=b;c++)
            printf("*");
        printf("\n");
    }


    return 0;
}
