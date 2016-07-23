#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
struct tree{
	char name[40];
};
 
bool compare(tree a, tree b)
{
	return strcmp(a.name, b.name) < 0;
}
int main()
{
	freopen("input.txt", "r", stdin);
	
	char input[40];
	tree words[1000000] = { 0 };
	int i, order = 0, count;
	double answer;
	for (i = 0;;i++)
	{
		if (gets(input) == NULL) break;
		strcpy(words[order++].name, input);
	}
	sort(words, words + order, compare);
	strcpy(input, words[0].name);
	count = 1;
	for (i = 1; i < order; i++)
	{
		if (!strcmp(input, words[i].name))
		{
			count++;
		}
		else{
			answer=(double)count/order;
			printf("%s %.4lf\n", input, answer*100);
			count = 1;
			strcpy(input, words[i].name);
		}
	}
	answer=(double)count/order;
	printf("%s %.4lf", input, answer*100);
}
