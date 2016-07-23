#include<stdio.h>
#include<vector>
#include<math.h>
 
using namespace std;
 
int a[25];
bool b[25]={0,};
 
int M,sum,bit,imsi;
vector<int> can;
int ccnt = 0;
bool DFS(int weight,int idx,int many)
{
    int i;
    if (many == 4 && weight == bit-1) return true;
    else if(many==4 && weight!=bit-1) return false;
    for (i = idx + 1; i < ccnt; i++)
    {
        if ((weight&can[i]) == 0)
        {
            weight += can[i];
            if (DFS(weight, i, many + 1)) return true;
            weight -= can[i];
        }
    }
    return false;
}
void dfs(int cnt,int idx)
{
    int i,j;
    if(cnt==sum)
    {
        imsi=0;
        int pow=1;
        for(i=0;i<M;i++)
        {
            if(b[i]==1)
                imsi+=pow;
            pow*=2;
        }
        can.push_back(imsi);
        ccnt++;
    }
    else if(cnt> sum) return;
 
    for(i=idx+1;i<M;i++)
    {
        if(b[i]==0)
        {
            b[i]=1;
            dfs(cnt+a[i],i);
            b[i]=0;
        }
    }
}
int main()
{
 
    int N;
    int i, j;
    scanf("%d", &N);
 
    while(N)
    {
        ccnt=0;
        sum = 0;
        N--;
 
        scanf("%d", &M);
        for (i = 0; i<M; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if(sum%4)
        {
            printf("no\n");
            continue;
        }
        sum /= 4;
        bit = 1;
        dfs(0,-1);
        for (i = 0; i < M; i++) bit <<= 1;
        if (DFS(0, -1, 0)) printf("yes\n");
        else printf("no\n");
        can.clear();
    }
}
 
