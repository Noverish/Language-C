#include <stdio.h>

int n;
int rear,front;
int map[30][30], queue[30], visit[30];

void BFS(int v)
{
	int i;

	visit[v] = 1;
	printf("%d에서 시작\n",v);
	queue[rear++]=v;
	while(front<rear)
	{
		v=queue[front++];
		for(i=1;i<=n;i++)
		{
			if(map[v][i]==1&& !visit[i])
			{
				visit[i] =1;
				printf("%d에서 %d로 이동\n",v,i);
				queue[rear++]=i;
			}
		}
	}
}

int main()
{
	int start;
	int v1, v2;

	scanf("%d%d",&n, &start);

	while(1)
	{
		scanf("%d%d",&v1,&v2);
		if (v1== -1 && v2==-1) break;
		map[v1][v2] = map[v2][v1]=1;
	}
	BFS(start);

	return 0;
}