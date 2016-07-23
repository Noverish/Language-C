#include <stdio.h>
char select(char (*town)[105], int i, int j) {

	if(town[i][j]=='R') {
		if(town[i-1][j]=='P')
			return 'P';
		else if(town[i+1][j]=='P') 
			return 'P';
		else if(town[i][j-1]=='P') 
			return 'P';
		else if(town[i][j+1]=='P') 
			return 'P';
		else
			return 'R';
	}
	else if(town[i][j]=='S') {
		if(town[i-1][j]=='R')
			return 'R';
		else if(town[i+1][j]=='R') 
			return 'R';
		else if(town[i][j-1]=='R') 
			return 'R';
		else if(town[i][j+1]=='R') 
			return 'R';
		else
			return 'S';
	}
	else if(town[i][j]=='P') {
		if(town[i-1][j]=='S')
			return 'S';
		else if(town[i+1][j]=='S') 
			return 'S';
		else if(town[i][j-1]=='S') 
			return 'S';
		else if(town[i][j+1]=='S') 
			return 'S';
		else
			return 'P';
	}


}

void fight(char (*town)[105], int row, int column) {
	int i,j;
	char save[105][105];

	for(i=1;i<=row;i++)
		for(j=1;j<=column;j++)
			save[i][j]=select(town,i,j);
	for(i=1;i<=row;i++)
		for(j=1;j<=column;j++)
			town[i][j]=save[i][j];

}
int main() {
	freopen("input.txt","r",stdin);

	int test_case;
	int row, column, times;
	int i;

	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {
		char town[105][105]={0};

		scanf("%d %d %d",&row,&column,&times);
		char ch=getchar();
		for(i=0;i<row;i++)
			gets(town[i+1]+1);

		for(i=0;i<times;i++)
			fight(town,row,column);

		for(i=1;i<=row;i++)
			printf("%s\n",(town[i]+1));
		printf("\n");
		
	}
	return 0;
}