#include<stdio.h>
 
int map[2001][2001] = { 0, };
 
int main()
{
	int n,i,j;
	int weight[2001] = { 0, };
 
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		weight[i] = 1000;
		scanf("%d", &weight[i]);
	}
	for (i = 1; i <= n; i++)
	{
		map[i][0] = weight[i-1] * i + map[i - 1][0];
		map[0][i] = weight[n - i] * i + map[0][i-1];
	}
 
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n-i; j++)
		{
			if (map[i - 1][j] + weight[i - 1] * (i + j) > map[i][j - 1] + weight[n - j] * (i + j))
				map[i][j] = map[i - 1][j] + weight[i - 1] * (i + j);
			else map[i][j]= map[i][j - 1] + weight[n - j] * (i + j);
		}
	}
	int max = 0;
 
	for (i = 0; i <= n; i++)
	{
		if (max < map[i][n - i])
			max = map[i][n - i];
		
	}
	printf("%d\n", max);
}
