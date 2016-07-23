#include<stdio.h>
 
int main()
{
	while (1)
	{
		double n;
		double a, b;
		if (scanf("%lf", &n) == EOF) break;
 
		while (1)
		{
 
			a = n;
			b = n / 9;
 
			if (b <= 2)
			{
				if (a > 9) printf("Ollie wins.\n");
				else printf("Stan wins.\n");
 
				break;
			}
			n /= 18;
		}
	}
}
