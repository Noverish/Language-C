#include<stdio.h>                           
#include<string.h>
#include<math.h>
int count[7] = { 0, };

 
bool situ2(int weight,bool check)
{
	if (weight == 0) return false;
	if (count[weight] < 4 && weight<=6 && weight!=0) return true;
 
	int i;
	for (i = 1; i < weight; i++)
	{
		count[i]++;
		if (i<=6 && count[i]<5 && situ2(weight - i,!check) == false)
		{
			count[i]--;
			return true;
		}
		count[i]--; 
	}
 
	return false;
}
int main()
{
	char input[1001] = { 0, };
	while (scanf("%s", input) != EOF)
	{
		for (int j = 0; j < 7; j++) count[j] = 0;
		bool check  = 1;
		check = 1;
		int weight = 0;
		for (int i = 0; i < strlen(input); i++)
		{
			check =!check;
			weight += input[i] - '0';
			count[input[i] - '0']++;
		}
		if (weight == 31) check = check;
		else 
		{
			check = !check;
			if (situ2(31 - weight,check) != true) check = !check;
		}
 
		char winner = 'A' + check;
		printf("%s %c\n", input, winner);
	}
}
