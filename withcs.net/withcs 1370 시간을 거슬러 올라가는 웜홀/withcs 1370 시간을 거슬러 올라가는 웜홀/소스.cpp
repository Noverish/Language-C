#include <stdio.h>
#define MAX_LINE 6000
#define MAX_POINT 500
#define INFINITY 999999999

struct LINE  {
    int u, v, w; // (u, v)�� ����ġ�� w. �ܹ��� �����ӿ� �������� 
}; 

struct LINE line[ MAX_LINE ]; // Edges[1 ... E] 
int dist[ MAX_POINT ]; // dist[x] : ���������κ��� x������ �ִܰ�� ����(�� ����) 

int BellmanFord(int start, int point_num, int line_num) // ���� ����Ŭ�� ������ True�� ������ 
{
	int i, repeat;
    for(i=0; i<point_num; i++) 
		dist[i] = INFINITY; 
    dist[start] = 0; 

    for(repeat = 0;repeat < point_num-1;repeat++)  { 
        for(i=0; i<line_num; i++) 
        { 
            int u = line[i].u;
			int v = line[i].v;
			int w = line[i].w; 
            if(dist[u] + w < dist[v]) dist[v] = dist[u] + w; 
        } 
    } 

    for(i=0; i<line_num; i++) { 
        if(dist[line[i].u] + line[i].w < dist[line[i].v]) 
            return 1; 
    } 
    return 0; // �̶� dist[x] �� ���� x�� ���� �ִܰ�� ���̸� �����ϰ� ���� 
} 

int main() {

	freopen("input.txt","r",stdin);

	int farm_num;
	int non_num, road_num, worm_holl;
	int i,j;
	int answer;

	scanf("%d",&farm_num);

	for(;farm_num>0;farm_num--) {
		for(i=0;i<MAX_LINE;i++)
			line[i].u=line[i].v=line[i].w=0;

		scanf("%d %d %d",&non_num,&road_num,&worm_holl);

		for(i=0;i<road_num*2;i+=2) {
			scanf("%d %d %d",&line[i].u,&line[i].v,&line[i].w);
			line[i+1].u=line[i].v;
			line[i+1].v=line[i].u;
			line[i+1].w=line[i].w;
		}

		for(j=0;j<worm_holl;j++) {
			scanf("%d %d %d",&line[i+j].u,&line[i+j].v,&line[i+j].w);
			line[i+j].w*=-1;
		}

		answer=BellmanFord(0,non_num,i+j);
		if(answer==1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}