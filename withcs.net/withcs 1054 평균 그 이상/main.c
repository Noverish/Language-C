#include <stdio.h>


int main()
{
    int cla_num;


    int a,b;
    int point[500][500];
    int sum = 0;
    int student[500];
    int aver[500];
    int over_num;
    float percent[500];

    scanf("%d",&cla_num);

    for(a=0;a<cla_num;a++)
    {
        sum=0;
        over_num=0;
        scanf("%d",&student[a]);


        for(b=0;b<student[a];b++)
        {
            scanf("%d",&point[a][b]);

            sum+=point[a][b];
        }

        aver[a] = sum/student[a];


        for(b=0;b<student[a];b++)
        {
            if(point[a][b]>aver[a])
            {
                over_num++;

            }
        }

        percent[a]=(float)over_num/(float)student[a];

    }

    for(a=0;a<cla_num;a++)
    {
        printf("%.3f%%\n",percent[a]*100);

    }





    return 0;
}
