#include <stdio.h>

int main()
{
    int ch;
    int real_sen[100000];
    int fixed_sen[100000];
    int i=0;
    int j=0;
    int a;

    for(;1;i++)
    {
        ch=getchar();
        real_sen[i]=ch;
        if(ch=='\n')
        {
            for(a=0;a<=i;a++)
            {
                fixed_sen[j]=real_sen[i-a];
                j++;
            }
            i=-1;
        }
        if(ch==EOF)
            break;
    }
    for(i=1;i<j;i++)
        printf("%c",fixed_sen[i]);
    return 0;
}
