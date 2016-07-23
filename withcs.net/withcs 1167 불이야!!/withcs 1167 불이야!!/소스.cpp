#include <stdio.h>

char maps[21][1001]={0};
int queue_J[1000][2]={0}, queue_F[1000][2]={0}, queue[1000][2];
int endJ=1, endF=1;

void pop(int *x, int *y, int *start) {

	*x = queue[*start][0];
	*y = queue[*start++][1];
}

void push_J(int x, int y, int *end) {

	queue_J[*end][0]=x;
	queue_J[(*end)++][1]=y;
}

void push_F(int x, int y, int *end) {

	queue_F[*end][0]=x;
	queue_F[(*end)++][1]=y;
}

void find_JF(int rows, int columns) {

	int i, j;
	for(i=1;i<=rows;i++)
		for(j=1;j<=columns;j++) {
			if(maps[i][j]=='J') {
				queue_J[0][0]=i;
				queue_J[0][1]=j;
				break;
			}
		}

	for(i=1;i<=rows;i++)
		for(j=1;j<=columns;j++) {
			if(maps[i][j]=='F') {
				push_F(i,j,&endF);
			}
		}

}

void change_to_f(int rows, int columns){
	int i, x, y;
	int end, start=0;

	for(i=0;i<endF;i++) {
			queue[i][0]=queue_F[i][0];
			queue[i][1]=queue_F[i][1];
	}

	end=endF;
	endF=0;

	for(;;start++) {
		if(start==end)
			return;

		pop(&x,&y,&start);

		if(maps[x-1][y]=='.') {
			maps[x-1][y]='F';
			push_F(x-1,y,&endF);
		}
		if(maps[x][y-1]=='.') {
			maps[x][y-1]='F';
			push_F(x,y-1,&endF);
		}
		if(maps[x][y+1]=='.') {
			maps[x][y+1]='F';
			push_F(x,y+1,&endF);
		}
		if(maps[x+1][y]=='.') {
			maps[x+1][y]='F';
			push_F(x+1,y,&endF);
		}
	}
}

int change_to_j(int rows, int columns){
	int i, x, y;
	int end, start=0;

	for(i=0;i<endJ;i++) {
			queue[i][0]=queue_J[i][0];
			queue[i][1]=queue_J[i][1];
	}

	end=endJ;
	endJ=0;

	for(;;start++) {
		if(start==end)
			break;

		pop(&x,&y,&start);

		if(maps[x-1][y]=='.') {
			maps[x-1][y]='J';
			push_J(x-1,y,&endJ);
			if(x-1==1)
				return -1;
		}
		if(maps[x][y-1]=='.') {
			maps[x][y-1]='J';
			push_J(x,y-1,&endJ);
			if(y-1==1)
				return -1;
		}
		if(maps[x][y+1]=='.') {
			maps[x][y+1]='J';
			push_J(x,y+1,&endJ);
			if(y+1==columns)
				return -1;
		}
		if(maps[x+1][y]=='.') {
			maps[x+1][y]='J';
			push_J(x+1,y,&endJ);
			if(x+1==rows)
				return -1;
		}
		
	}
	if(endJ==0)
		return 1;
}

int escape(int rows, int columns) {

	int times=0;
	int check;
	int i;


	for(;;times++) {
		
		change_to_f(rows, columns);

		for(i=1;i<=rows;i++)
			printf("%s\n",maps[i]);

		check=change_to_j(rows, columns);

		for(i=1;i<=rows;i++)
			printf("%s\n",maps[i]);

		if(check==-1)
			return times;
		if(check==1)
			return -1;

	}


}

int main() {

	freopen("input.txt","r",stdin);

	int row, column;
	int i;
	int impossible;
	
	scanf("%d %d",&row, &column);

	for(i=1;i<20;i++)
		maps[i][0]=32;

	for(i=0;i<=row;i++)
		gets(maps[i]+1);

	find_JF(row,column);

	impossible=escape(row,column);

	if(impossible==-1)
		printf("IMPOSSIBLE");

	printf("%d",impossible);



	return 0;
}