#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    int sentence[100000];
    int i=0;
    int blank_on=0;
    int no_blank;

    for(i=0;1;i++)
    {
        ch=getchar();
        sentence[i]=ch;

        if(ch==' '||ch=='\t'||ch=='\r')
            sentence[i]=ch;
        else
        {
            if(ch=='\n')
            {
                i=no_blank+1;
                sentence[i]='\n';
                continue;
            }
            else
            {
                no_blank=i;
            }
        }

        if(ch==EOF)
            break;
    }
    for(ch=0;ch<i-1;ch++)
        printf("%c",sentence[ch]);
}
