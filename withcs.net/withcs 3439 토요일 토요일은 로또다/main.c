#include <stdio.h>

int main()
{
    int lotto_num;
    int num[100][6];
    int a,b;
    int ch;
    int check_list[50];
    while(1)
    {
        scanf("%d",&lotto_num);
        if(lotto_num==0) break;
        for(a=0;a<50;a++) check_list[a]=0;
        for(a=0;a<lotto_num;a++)
        {
            for(b=0;b<6;b++)
            {
                scanf("%d",&ch);
                num[a][b]=ch;
            }
        }

        for(a=0;a<lotto_num;a++)
        {
            for(b=0;b<6;b++)
            {
                ch=num[a][b];
                check_list[ch]++;
            }
        }
        for(a=1;a<50;a++)
        {
            if(check_list[a]==0)
            {
                printf("No\n");
                break;
            }
            if(a==49) printf("Yes\n");

        }
    }
    return 0;
}
