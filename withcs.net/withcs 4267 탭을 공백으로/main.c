#include <stdio.h>

int main()
{
    int i,j;
    int sen[10000];
    int ch;
    int tab_start=1;

    for(i=0;1;i++)
    {
        ch=getchar();
        if(ch=='\t')
        {
            switch(tab_start)
            {
            case 1:
                {
                    for(j=0;j<4;j++)
                    {
                        sen[i]=' ';
                        i++;
                    }
                    i--;
                    tab_start=1;
                    break;
                }
            case 2:
                {
                    for(j=0;j<3;j++)
                    {
                        sen[i]=' ';
                        i++;
                    }
                    i--;
                    tab_start=1;
                    break;
                }
            case 3:
                {
                    for(j=0;j<2;j++)
                    {
                        sen[i]=' ';
                        i++;
                    }
                    i--;
                    tab_start=1;
                    break;
                }
            case 4:
                {
                    for(j=0;j<1;j++)
                    {
                        sen[i]=' ';
                        i++;
                    }
                    i--;
                    tab_start=1;
                    break;
                }
            }
        }
        else if(ch=='\n'||ch==EOF)
        {
            for(j=0;j<i;j++)
            {
                printf("%c",sen[j]);
            }
            if(ch=='\n') printf("\n");
            if(ch==EOF) break;
            i=-1;
            tab_start=1;
            continue;
        }
        else
        {
            sen[i]=ch;
            if(tab_start==4) tab_start=1;
            else tab_start++;
        }
    }
    return 0;
}
