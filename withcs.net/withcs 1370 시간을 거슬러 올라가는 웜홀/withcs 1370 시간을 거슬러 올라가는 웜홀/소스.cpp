#include <stdio.h>
#define MAX_LINE 6000
#define MAX_POINT 500
#define INFINITY 999999999

struct LINE  {
    int u, v, w; // (u, v)의 가중치가 w. 단방향 에지임에 유의하자 
}; 

struct LINE line[ MAX_LINE ]; // Edges[1 ... E] 
int dist[ MAX_POINT ]; // dist[x] : 시작점으로부터 x까지의 최단경로 길이(의 상한) 

int BellmanFord(int start, int point_num, int line_num) // 음수 사이클이 있으면 True를 리턴함 
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
    return 0; // 이때 dist[x] 는 실제 x에 오는 최단경로 길이를 저장하고 있음 
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