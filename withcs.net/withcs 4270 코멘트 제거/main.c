#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sen[50000];
    int ch;
    int i,j;
    int comment_on=0;

    for(i=0;1;i++)
    {
        ch=getchar();
        if(ch==EOF)
        {
            i--;
            break;
        }
        else if(ch=='"')
        {
            if(comment_on==1) comment_on=0;
            else comment_on=1;

            sen[i]=ch;
        }
        else if(ch=='/')
        {
            if(comment_on==1)
            {
                sen[i]=ch;
                continue;
            }
            ch=getchar();
            if(ch=='*')
            {
                while(1)
                {
                    ch=getchar();
                    if(ch=='\n')
                    {
                        sen[i]='\n';
                        i++;
                    }
                    if(ch=='*')
                    {
                        ch=getchar();
                        if(ch==EOF) break;
                        if(ch=='/')
                        {
                            i--;
                            break;
                        }
                    }
                    if(ch==EOF) break;
                }
                if(ch==EOF) break;
            }
            else if(ch==EOF)
            {
                sen[i]='/';
                break;
            }
            else
            {
                sen[i]='/';
                i++;
                sen[i]=ch;
            }
        }
        else sen[i]=ch;

    }

    for(j=0;j<=i;j++) printf("%c",sen[j]);
    return 0;
}
