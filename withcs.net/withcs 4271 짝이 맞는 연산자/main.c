#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int line_num;
    int rracket=0, bracket=0, braces=0;
    int ch;
    int sen[5000];
    int for_out=0;
    char ans='Y';
    scanf("%d",&line_num);
    ch=getchar();
    while(line_num>0)
    {
        ans='Y';
        rracket=0;
        bracket=0;
        braces=0;


        while(for_out==0)
        {
            ch=getchar();
            switch (ch)
            {
                case '(' :
                    {
                        if(bracket!=0||braces!=0) ans='N';
                        else rracket++;
                        break;
                    }
                case ')' :
                    {
                        if(bracket!=0||braces!=0) ans='N';
                        else if(rracket<=0) ans='N';
                        else rracket--;
                        break;
                    }
                case '[' :
                    {
                        if(rracket!=0||braces!=0) ans='N';
                        else bracket++;
                        break;
                    }
                case ']' :
                    {
                        if(rracket!=0||braces!=0) ans='N';
                        else if(bracket<=0) ans='N';
                        else bracket--;
                        break;
                    }
                case '{' :
                    {
                        if(rracket!=0||bracket!=0) ans='N';
                        else braces++;
                        break;
                    }
                case '}' :
                    {
                        if(rracket!=0||bracket!=0) ans='N';
                        else if(braces<=0) ans='N';
                        else braces--;
                        break;
                    }
                case EOF :
                case '\n' :
                    {
                        for_out=1;
                        break;
                    }
                default :
                    {
                        break;
                    }

            }
        }

        if(rracket==0 && bracket==0 && braces==0) a=0;
        else ans='N';
        if(line_num==1)
        {
            printf("%c",ans);
            line_num--;
            for_out=0;
        }
        else
        {
            printf("%c\n",ans);
            line_num--;
            for_out=0;
        }

    }


    return 0;
}
