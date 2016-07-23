#include <stdio.h>

int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int number, section_num;
	int num[100000];
	int sum_num[100000];
	int sec_start, sec_end;
	int ans=0;
	int sum=0;
	int i,j;

	scanf("%d %d",&number, &section_num);

	for(i=0;i<number;i++) scanf("%d",&num[i]);

	sum_num[0]=num[0];

	for(i=1;i<number;i++) {
		sum_num[i]=sum_num[i-1]+num[i];
	}


	for(i=0;i<section_num;i++)
	{
		scanf("%d %d",&sec_start,&sec_end);

		if(sec_start==0) sum=sum_num[sec_end];
		else sum=sum_num[sec_end]-sum_num[sec_start-1];
		
		ans=max(ans, sum);

		sum=0;
	}

	printf("%d",ans);

	return 0;
}

