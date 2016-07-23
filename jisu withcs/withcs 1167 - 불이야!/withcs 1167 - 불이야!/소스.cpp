#include<stdio.h>
#include<queue>
#include<utility>
 
using namespace std;
 
queue<pair<int,int> > FIRES;
queue<pair<int, pair<int,int> > > J;
pair<int,int> temp;
pair<int, pair<int,int> > tmp;
int field[2001][2001];
bool Jdid[2001][2001];
int F=0;
int main()
{
    char n,c;
    int N,K;
    int i,j; for(i=0;i<2001;i++)for(j=0;j<2001;j++)field[i][j]=-1;
    scanf("%d %d",&N,&K);
    getchar();
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=K;j++)
        {
            scanf("%c",&c);
            if(c=='#') field[i][j]=0;
            else if(c=='F'){
                temp.first=i; temp.second=j;
                FIRES.push(temp);
                field[i][j]=1;
            }
            else if(c=='J')
            {
                tmp.first=1;
                tmp.second.first=i;
                tmp.second.second=j;
                J.push(tmp);
                Jdid[i][j]=1;
            }
        }
        getchar();
    }
 
    int idx=1;
 
    while(!FIRES.empty())
    {
        temp=FIRES.front();
        if(temp.second<K && (field[temp.first][temp.second+1]==-1 ||field[temp.first][temp.second+1]>field[temp.first][temp.second]+1 ))
        {
            temp.second++;
            FIRES.push(temp);
            field[temp.first][temp.second]=field[temp.first][temp.second-1]+1;
            temp.second--;
        }
        if(temp.second>1 && (field[temp.first][temp.second-1]==-1 ||field[temp.first][temp.second-1]>field[temp.first][temp.second]+1 ))
        {
            temp.second--;
            FIRES.push(temp);
            field[temp.first][temp.second]=field[temp.first][temp.second+1]+1;
            temp.second++;
        }
        if(temp.first<N &&( field[temp.first+1][temp.second]==-1 ||field[temp.first+1][temp.second]>field[temp.first][temp.second]+1 ))
        {
            temp.first++;
            FIRES.push(temp);
            field[temp.first][temp.second]=field[temp.first-1][temp.second]+1;
            temp.first--;
        }
        if(temp.first>1 && (field[temp.first-1][temp.second]==-1 ||field[temp.first-1][temp.second]>field[temp.first][temp.second]+1 ))
        {
            temp.first--;
            FIRES.push(temp);
            field[temp.first][temp.second]=field[temp.first+1][temp.second]+1;
            temp.first++;
        }
        FIRES.pop();
    }
    bool check=1;
    while(!J.empty())
    {
        tmp=J.front();
        if(tmp.second.first == 1 ||tmp.second.first== N || tmp.second.second==1 ||tmp.second.second==K)
        {
            check=0;
            printf("%d\n",tmp.first);
            break;
        }
        if(field[tmp.second.first][tmp.second.second+1]==-1 || field[tmp.second.first][tmp.second.second+1] > tmp.first+1)
        {
            tmp.first++; tmp.second.second++;
            if(!Jdid[tmp.second.first][tmp.second.second])
            {
                Jdid[tmp.second.first][tmp.second.second]=1;
                J.push(tmp);
            }
            tmp.first--; tmp.second.second--;
        }
        if(field[tmp.second.first][tmp.second.second-1]==-1 || field[tmp.second.first][tmp.second.second-1] > tmp.first+1)
        {
            tmp.first++; tmp.second.second--;
            if(!Jdid[tmp.second.first][tmp.second.second])
            {
                Jdid[tmp.second.first][tmp.second.second]=1;
                J.push(tmp);
            }
            tmp.first--; tmp.second.second++;
        }
        if(field[tmp.second.first+1][tmp.second.second]==-1 || field[tmp.second.first+1][tmp.second.second] > tmp.first+1)
        {
            tmp.first++; tmp.second.first++;
            if(!Jdid[tmp.second.first][tmp.second.second])
            {
                J.push(tmp);
                Jdid[tmp.second.first][tmp.second.second]=1;
            }
            tmp.first--; tmp.second.first--;
        }
        if(field[tmp.second.first-1][tmp.second.second]==-1 || field[tmp.second.first-1][tmp.second.second] > tmp.first+1)
        {
            tmp.first++; tmp.second.first--;
            if(!Jdid[tmp.second.first][tmp.second.second])
            {
                J.push(tmp);
                Jdid[tmp.second.first][tmp.second.second]=1;
            }
            tmp.first--; tmp.second.first++;
        }
        J.pop();
    }
    if(check) printf("IMPOSSIBLE\n");
    return 0;
}
