#include <stdio.h>

int neck_table_0[13000]={0}, neck_table_1[13000]={0};

void copy() {
	int a;
	
	for(a=0;a<13000;a++)
		neck_table_0[a] = neck_table_1[a];
}


int main() {

	int neck_num, wei_limit;
	int neck_weight[4000]={0}, neck_value[4000]={0};
	
	int i,j;
	int ans=0;

	scanf("%d %d",&neck_num,&wei_limit);


	for(i=0;i<neck_num;i++) 
		scanf("%d %d",&neck_weight[i],&neck_value[i]);

	for(i=0;i<neck_num;i++) {


		for(j=0;  j+neck_weight[i]<wei_limit + 3 ;j++) {
			neck_table_1[ j+neck_weight[i] ] = (neck_table_0[ j+neck_weight[i] ] > neck_table_0[j] + neck_value[i]) ? neck_table_0[ j+neck_weight[i] ] : neck_table_0[j] + neck_value[i];
		}

		copy();

	}


	for(i=0;i<=wei_limit;i++) {
		if(neck_table_1[i]>ans) ans=neck_table_1[i];
	}

	printf("%d",ans);
	
	return 0;
}