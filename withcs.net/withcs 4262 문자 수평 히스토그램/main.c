#include <stdio.h>

int main()
{

    int ch;
    int num_num[1000];

    for (ch=0;ch<1000;ch++)
        num_num[ch]=0;

    while(1)
    {
        ch=getchar();
        num_num[ch]++;




        if(ch==EOF)
        {
            break;
        }

    }
    int i;
    int j;
    for(i=33;i<127;i++)
    {
        printf("%c: ",i);
        for(j=0;j<num_num[i];j++)
            printf("*");
        printf("\n");
    }



    return 0;
}

