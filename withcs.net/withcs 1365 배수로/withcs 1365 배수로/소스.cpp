#include <stdio.h>

int river[200][200];
int queue[1000];
int front = 0;
int end = 0;

void push(int a) {
	queue[end++]=a;
}

int pop(void) {
	if(front!=end)
		return queue[front++];
	else
		return -1;
}

int find_BFS(int river_num, int point_num) {
	int parent[300] = {0};
	int i;
	int now_from;
	int min=0x7fffffff;
	int find_end=0;

	push(1);

	while(1) {
		now_from=pop();
		if(now_from==-1)
			return -1;
		for(i=1;i<=point_num;i++) {
			if(river[now_from][i]!=0 && parent[i]==0) {
				parent[i]=now_from;
				push(i);
				if(i==point_num) {
					find_end=1;
					break;
				}
			}
		}
		if(find_end==1)
			break;
	}

	while(1) {
		if(river[parent[i]][i]<min)
			min=river[parent[i]][i];
		if(parent[i]==1)
			break;
		i=parent[i];
	}

	i=point_num;

	while(1) {
		river[i][parent[i]]=river[parent[i]][i]-min;
		river[parent[i]][i]-=min;
		if(parent[i]==1)
			break;
		i=parent[i];
	}

	return min;
}

int main() {

	freopen("input.txt","r",stdin);

	int river_num, point_num;
	int i, from, to, value;
	int save, answer=0;

	scanf("%d %d",&river_num,&point_num);

	for(i=0;i<river_num;i++) {
		scanf("%d %d %d",&from, &to, &value);
		river[from][to]=value;
	}

	while(1) {
		save=find_BFS(river_num,point_num);
		front=end=0;
		if(save==-1)
			break;
		answer+=save;
	}

	printf("%d",answer);

	return 0;
}