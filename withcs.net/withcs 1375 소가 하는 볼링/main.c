#include <stdio.h>

int MAX(int x, int y)
{
    if(x>y) return x;
    else return y;
}

int main()
{
    int bowl[400][400];
    int row_num;
    int a,b;
    int ch;

    scanf("%d",&row_num);
    for(a=1;a<=row_num;a++)
    {
        for(b=1;b<=a;b++)
        {
            scanf("%d",&ch);
            bowl[a][b]=ch;
        }
    }
    for(a=row_num-1;a>0;a--)
    {
        for(b=a;b>0;b--)
        {
            bowl[a][b]+=MAX(bowl[a+1][b],bowl[a+1][b+1]);
        }
    }
    printf("%d",bowl[1][1]);

    return 0;
}
