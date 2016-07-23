#include <stdio.h>

void main()
{
    int match_num;
    int i;
    int sum_score[500], gap_score[500];
    int real_score1[500], real_score2[500];

    scanf("%d",&match_num);

    for(i=0;i<match_num;i++)
    {
        scanf("%d %d",&sum_score[i],&gap_score[i]);

        real_score1[i] = (sum_score[i]+gap_score[i])/2;
        real_score2[i] = (sum_score[i]-gap_score[i])/2;
    }

    for(i=0;i<match_num;i++)
    {
        if(real_score2[i]<0)
        {
            printf("impossible\n");
        }
        else if((real_score1[i]+real_score2[i])!= sum_score[i])
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d %d\n",real_score1[i],real_score2[i]);
        }


    }
}
