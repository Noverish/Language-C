#include <stdio.h> 
int max(int a, int b); 
int main() { 
	int weight[10] = {0, 5, 10,20}; 
	int price[10] = {0, 50, 60, 140}; 
	int i, j; 
	int p[11][31]; 
	for(i = 0; i < 31; i++) 
		p[0][i] = 0; 
	for(i = 0; i < 11; i++) 
		p[i][0] = 0; 
	for(i = 1; i <= 10; i++) 
		for(j =1; j <= 30; j++) { 
			if(weight[i] <= j) 
				p[i][j] = max( p[i-1][j], price[i] + p[i-1][j - weight[i]] ); 
			else p[i][j] = p[i-1][j]; 
		} 
	printf("0-1 knapsack best solution is %d \nIn Dynamic Programming\n",p[3][30]); 
	return 0; 
} 
int max(int a, int b) { 
	return((a > b) ? a : b); 
}