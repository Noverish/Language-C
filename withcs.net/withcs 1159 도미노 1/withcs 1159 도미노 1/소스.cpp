#include <stdio.h>
void union_find(int *domino, int x, int y, int domino_num) {
	int i;

	for(i=1;i<=domino_num;i++) {
		if(domino[i]==y)
			domino[i]=x;
	}
}

int main() {

	freopen("input.txt","r",stdin);

	int domino[100005];
	int test_case;
	int index[100005]={0};
	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {
		
		int domino_num, relation_num, answer=0;;
		int i,x,y;

		for(i=0;i<100005;i++) {
			domino[i]=i;
			index[i]=0;
		}
		scanf("%d %d",&domino_num,&relation_num);

		for(i=0;i<relation_num;i++) {
			scanf("%d %d",&x, &y);

			if(domino[y]==y) {
				if(domino[x]!=x)
					x=domino[x];
				union_find(domino, x, y,domino_num);
			}
		}

		for(i=1;i<=domino_num;i++)
			index[ domino[i] ]++;

		for(i=1;i<=domino_num;i++)
			if(index[i]>0)
				answer++;

		printf("%d\n",answer);

	}
	return 0;
}