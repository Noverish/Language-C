#include <stdio.h>
#include <math.h>

int main()
{
    int x1,y1,r1,x2,y2,r2;
    int case_num;
    int i;
    float length;
    int ans[1000];

    scanf("%d",&case_num);

    for(i=0;i<case_num;i++)
    {

        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);

        length = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

        if(length<r1 || length<r2)
        {
            if(r1>r2)
                if(r1<r2+length)
                    ans[i]=2;
                if(r1==r2+length)
                    ans[i]=1;
                if(r1>r2+length)
                    ans[i]=0;
            if(r1<r2)
                if(r2<r1+length)
                    ans[i]=2;
                if(r2==r1+length)
                    ans[i]=1;
                if(r2>r1+length)
                    ans[i]=0;
            if(r1==r2)
            {
                if(length==0)
                    ans[i] = -1;
                else
                    ans[i] = 2;
            }
        }
        else
        {
            if(length>r1+r2)
                ans[i] = 0;
            if(length==r1+r2)
                ans[i] = 1;
            if(length<r1+r2)
                ans[i] = 2;
        }




    }

    for(i=0;i<case_num;i++)
        printf("%d\n",ans[i]);

    return 0;
}
