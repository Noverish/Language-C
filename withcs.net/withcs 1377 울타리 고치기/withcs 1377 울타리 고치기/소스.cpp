#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647

int compare(const void *A, const void *B) {
	int a = *((int *) A);
	int b = *((int *) B);
	if(a>b)
		return 1;
	else if(a<b)
		return -1;
	else
		return 0;
}

int main() {
    
	int panel_len[20001];
	int panel_num;
	long long cost;
	int i;
	int intercept;
	int save;

	for(i=0;i<20000;i++)
		panel_len[i]=MAX;

	scanf("%d",&panel_num);

	for(i=0;i<panel_num;i++)
		scanf("%d",&panel_len[i]);

    qsort(panel_len, panel_num, sizeof(int),compare);
    
	for(;panel_num>0;panel_num--) {

		if(panel_len[1]==MAX) break;

		save=panel_len[0]+panel_len[1];
		
		cost+=save;

		for(i=0;panel_len[i]<save;i++);

		intercept=i;

		for(i=2;i<intercept;i++)
		    panel_len[i-2]=panel_len[i];
		panel_len[i-2]=save;

		for(;i<panel_num;i++)
		    panel_len[i-1]=panel_len[i];

		panel_len[panel_num-1]=MAX;
	}

	printf("%lld",cost);

	return 0;
}