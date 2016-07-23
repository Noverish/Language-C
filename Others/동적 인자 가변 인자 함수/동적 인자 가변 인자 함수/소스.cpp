#include <stdio.h>
#include <math.h>

double addd(double a, double b) {
	return a+b;
}

float addf(float a, float b) {
	return a+b;
}

inline double __CRTDECL add(_In_ double _X, _In_ double _Y)
{return (addd(_X,_Y)); }

inline float __CRTDECL add(_In_ float _X, _In_ float _Y)
{return (addf(_X,_Y)); }

int add(int a, int b) {
	return a+b;
}

int main() {
	
	printf("%d\n",add(1,5));
	printf("%f\n",add((float)1.5,(float)5.5));
	printf("%lf\n",add((double)1.4,(double)5.7));
	
	return 0;
}