#include <stdio.h>

int queue[10000];
int front=0;
int end=0;
int answer=0;

int pop(void) {
	answer++;
	return queue[front++];
}
void push(int a) {
	queue[end++]=a;
}

void domino(int (*rel)[2], int rel_num) {
	int now_domino;
	int i;
	while(1) {
		now_domino=pop();

		for(i=0;i<rel_num;i++)
			if(rel[i][0]==now_domino)
				push(rel[i][1]);

		if(end==front)
			break;
	}
}

int main() {
	freopen("input.txt","r",stdin);
	int test_case;
	int num_domino, rel_domino, down_domino, hand_domino;
	int i;

	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {
		int relation[10000][2]={0};

		scanf("%d %d %d",&num_domino,&rel_domino,&down_domino);

		for(i=0;i<rel_domino;i++)
			scanf("%d %d",&relation[0], &relation[1]);

		for(i=0;i<down_domino;i++) {
			scanf("%d",&hand_domino);
			push(hand_domino);
		}

		domino(relation,rel_domino);

		printf("%d",answer);

		front=end=answer=0;
		for(i=0;i<10000;i++)
			relation[i][0]=relation[i][1]=0;
		
	}
	return 0;
}