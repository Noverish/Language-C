#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    int sen[30000];
    int i,j;
    for(i=0;i<30000;i++) sen[i]=0;
    for(i=3;ch!=EOF;i+=3)
    {
        ch=getchar();
        sen[i]=ch;
        if(sen[i]=='\n'||sen[i]==EOF)
        {
            if(sen[i]==EOF)
            {
                for(j=1;j<i;j++) if(sen[j]!=0) printf("%c",sen[j]);
                break;
            }
            if(sen[i]=='\n')
            {
                sen[i-1]='\n';
                for(j=1;j<=i;j++) if(sen[j]!=0) printf("%c",sen[j]);
            }
            for(i=0;i<30000;i++) sen[i]=0;
            i=0;
            if(ch==EOF) break;
        }
        else if(i%60==0)
        {
            i+=3;
            ch=getchar();
            sen[i]=ch;
            if(sen[i-6]==' '||sen[i-3]==' '||sen[i]==' ')
            {
                if(sen[i-6]==' ')
                {
                    sen[i-6]='\n';
                    sen[i+3]=sen[i];
                    sen[i]=sen[i-3];
                    sen[i-3]=0;
                    i+=3;

                }
                else if(sen[i-3]==' ')
                {
                    sen[i-3]='\n';

                }
                else if(sen[i]==' ')
                {
                    sen[i-1]='\n';
                    i-=3;
                }
            }
            else
            {
                sen[i-4]='\n';
                sen[i-5]='-';
                sen[i+3]=sen[i];
                sen[i]=sen[i-3];
                sen[i-3]=0;
                i+=3;
            }
        }
    }
    return 0;
}
