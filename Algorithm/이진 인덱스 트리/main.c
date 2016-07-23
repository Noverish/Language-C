 #include<stdio.h>
#include<algorithm>
using namespace std;
#define MaxSize 10000
#define INT_MAX 2147483647
FILE *fin=fopen("input.txt","r");
FILE *fout=fopen("output.txt","w");
int n, s, e, data[MaxSize], index_tree[MaxSize*2+1], size, min;
void input()
{
    int i;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {

    }
    fscanf(fin,"%d%d", &s, &e);
}
int minf(int i,int j)
{
    if(i>j) return j;
    return i;
}
void process()
{
    int i;
    int x,y;
    int pos;

    /* setting */
    size=1;
    while(size<n) size*=2;
    fill(index_tree+1, index_tree+size, INT_MAX);
    for(i=1; i<=n; i++) index_tree[i+size-1] = data[i];
    for(i=1; i<=n; i++)
    {
        pos = size+i-1;
        while(pos/2!=0)
        {
            index_tree[pos/2] = minf(index_tree[pos], index_tree[pos/2]);
            pos/=2;
        }
    }

    /* search */
    x=s+size-1;
    y=e+size-1;
    min=INT_MAX;
    while(x<y)
    {
        if(x%2==1)
        {
            min=minf(min, index_tree[x]);
            x++;
        }
        if(y%2==0)
        {
            min=minf(min,index_tree[y]);
            y--;
        }
        x/=2;
        y/=2;
    }
    if(x==y)
    {
        min=minf(min,index_tree[x]);
    }
}
void output()
{
    fprintf(fout,"%d",min);
}
int main()
{
    input();
    process();
    output();
    fcloseall();
    return 0;
}

