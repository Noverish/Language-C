#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
 
using namespace std;
 
#define N 4000
int a[N], b[N], c[N], d[N],n;
int X[N*N], Y[N*N], l = 0;
int main()
{
	int i, j,lx,ly;
	scanf("%d", &n);
 
	for (i = 0; i < n; i++)
	scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			X[l] = a[i] + b[j];
			Y[l++] = c[i] + d[j];
		}
	}
 
	sort(X, X + l); sort(Y, Y + l);
 
 
	lx = 0; ly = l-1;
	int cnta, cntb,answer=0;
 
	while (1)
	{
		if (lx >= l || ly <= -1) break;
		if (X[lx] + Y[ly] == 0)
		{
			for (i = lx; i < l; i++)
				if (X[i] != X[lx]) break;
			cnta = i;
 
			for (i = ly; i >= 0; i--)
				if (Y[i] != Y[ly]) break;
			cntb = i;
 
			answer += (cnta - lx) * (ly - cntb); 
			lx = cnta, ly = cntb;
		}
		else if (X[lx] + Y[ly] > 0) ly--;
		else lx++;
 
	}
 
	printf("%d\n", answer);
	return 0;
}
