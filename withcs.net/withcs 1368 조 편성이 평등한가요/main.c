#include <stdio.h>

int Max(int a, int b)
{
    if(a>b) return a;
    else return b;
}
int Min(int c, int d)
{
    if(c>d) return d;
    else return c;
}

int main()
{

    int max_hei[100000];
    int min_hei[100000];
    int dog_num, team_num;
    int i;
    int n;
    int start_num, end_num;
    int max_num, min_num;
    int ans[200000];


    scanf("%d %d",&dog_num,&team_num);

    for(i=0;i<dog_num;i++)
    {
        scanf("%d",&max_hei[50000+i]);
        min_hei[50000+i] = max_hei[50000+i];
    }

    for(n=49999;n>0;n--)
    {
        max_hei[n]=Max(max_hei[2*n],max_hei[2*n+1]);
        min_hei[n]=Min(min_hei[2*n],min_hei[2*n+1]);
    }

    int saved_start,saved_end;

    for(i=0;i<team_num;i++)
    {

        scanf("%d %d",&start_num,&end_num);
        start_num+=49999;
        end_num+=49999;

        saved_start = start_num;
        saved_end = end_num;


        max_num=0;
        min_num=9999999;

        while(start_num<end_num)
        {
            if(start_num%2==1)
            {
                max_num=Max(max_num,max_hei[start_num]);
                start_num++;
            }
            if(end_num%2==0)
            {
                max_num=Max(max_num,max_hei[end_num]);
                end_num--;
            }
            start_num/=2;
            end_num/=2;
        }
        if(start_num==end_num)
        {
            max_num=Max(max_num,max_hei[start_num]);
        }

        start_num = saved_start;
        end_num = saved_end;

        while(start_num<end_num)
        {
            if(start_num%2==1)
            {
                min_num=Min(min_num,min_hei[start_num]);
                start_num++;
            }
            if(end_num%2==0)
            {
                min_num=Min(min_num,min_hei[end_num]);
                end_num--;
            }
            start_num/=2;
            end_num/=2;
        }
        if(start_num==end_num)
        {
            min_num=Min(min_num,min_hei[start_num]);
        }


        printf("%d",max_num-min_num);

        if(i==team_num-1)
            break;
        else printf("\n");
    }
    return 0;
}
