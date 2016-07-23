#include <stdio.h>

int main()
{

    int ch;
    int sentence[100000];
    int i;
    int not_word = 0;


    for(i=0;1;)
    {
        ch=getchar();


        if(not_word == 1)
        {
            if((48<=ch&&ch<=57)||(65<=ch&&ch<=90)||(97<=ch&&ch<=122))
            {
                sentence[i]=ch;
                i++;
                not_word=0;
                continue;
            }
            else
            {
                if(ch==EOF)
                    break;
                continue;
            }
        }

        if((48<=ch&&ch<=57)||(65<=ch&&ch<=90)||(97<=ch&&ch<=122))
        {
            sentence[i]=ch;
            i++;

        }
        else
        {
            sentence[i]='\n';
            i++;
            not_word=1;
        }





        if(ch==EOF)
        {
            break;
        }

    }

    for(ch=0;ch<i-1;ch++)
        printf("%c",sentence[ch]);



    return 0;
}

