#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    int sentence[100000];
    int max_sen[100000];
    int i,j;
    int line_start=0;
    int max_line=0;

    for(i=0;1;i++)
    {
        ch=getchar();
        sentence[i]=ch;

        if(ch=='\n')
        {
            if(i-line_start>max_line)
            {
                max_line=i-line_start;
                for(j=0;j<max_line;j++)
                    max_sen[j]=sentence[line_start+j];
            }
            line_start=i+1;
        }

        if(ch==EOF)
            break;
    }

    printf("%d\n",max_line);
    for(j=0;j<max_line;j++)
    {
        printf("%c",max_sen[j]);
    }


}
