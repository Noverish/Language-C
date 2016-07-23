#include <stdio.h>
//http://blog.naver.com/stories2/70187386369
void input();
void knapsack();
void output();

int data_num,max_volume,max_worth;
int database[4000][3],backpack[3][1000000];

int main()
{
    input();
    knapsack();
    output();
    return 0;
}

void output()
{
    printf("%d",max_worth);
}

void knapsack()
{
    int max_length,i,t;
    backpack[1][ database[1][1] ]=database[1][2];
    max_length=database[1][1];
    for(i=2;i<=data_num;i++)
    {
        
        max_length+=database[i][1];
        backpack[2][database[i][1]]=database[i][2];
        for(t=1;t<=max_length;t++)
        {
            if(t>database[i][1] && backpack[1][t-database[i][1]]!=0)
            {
                backpack[2][t]=backpack[1][t-database[i][1]]+database[i][2];
            }
            if(backpack[1][t]>backpack[2][t])
            {
                backpack[2][t]=backpack[1][t];
            }
        }
        for(t=1;t<=max_length;t++)
        {
            backpack[1][t]=backpack[2][t];
            backpack[2][t]=0;
        }
    }
    max_worth=backpack[1][max_volume];
}

void input()
{
    int i;
 //   freopen("input.txt","r",stdin);
    scanf("%d %d\n",&data_num,&max_volume);
    //printf("data_num : %d max_volume : %d\n",data_num,max_volume);
    for(i=1;i<=data_num;i++)
    {
        scanf("%d %d",&database[i][1],&database[i][2]);
        //printf("%d %d\n",database[i][1],database[i][2]);
    }
}