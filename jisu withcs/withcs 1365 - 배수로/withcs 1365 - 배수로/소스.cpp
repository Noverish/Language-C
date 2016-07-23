#include<fstream>
#include<cstring>
#define N 220
#define oo 0x7fffffff
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;
int n,m,d,que[N*N],f[N];
int dg[N],grp[N][N],net[N][N];
int bfs();
void change(int k);
int main()
{
    int i,s,e,c;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&s,&e,&c);
        s--; e--;
        if(s==e){continue;}
        grp[s][dg[s]++]=e;
        grp[e][dg[e]++]=s;
        net[s][e]+=c;
    }
    while(1){
        c=bfs();
        if(c==0) break;
        d+=c;
        change(c);
    }
    printf("%d\n",d);
    return 0;
}
 
int bfs()
{
    int h,t,i,x,y,l=oo;
    h=t=0;
    memset(f,-1,sizeof(f)); f[0]=0;
    que[h++]=0;
    while(h!=t){
        x=que[t++];
        if(x==n-1) return l;
        for(i=0;i<dg[x];i++){
            y=grp[x][i];
            if(f[y]==-1 && net[x][y]>0){
                l=MIN(l,net[x][y]);
                f[y]=x;
                que[h++]=y;
            }
        }
    }
    return 0;
}
 
void change(int k)
{
    int x=n-1;
    while(x>0){
        net[x][f[x]]+=k;
        net[f[x]][x]-=k;
        x=f[x];
    }
}
