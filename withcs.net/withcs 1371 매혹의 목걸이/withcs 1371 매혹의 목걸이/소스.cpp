#include <stdio.h>


int main() {

	int neck_num, wei_limit;
	int neck_weight[4000]={0}, neck_value[4000]={0};
	int neck_table_value[13000]={0}, neck_table_can[13000]={0};
	int i,j;
	int ans=0;

	scanf("%d %d",&neck_num,&wei_limit);

	for(i=0;i<neck_num;i++) {
		scanf("%d %d",&neck_weight[i],&neck_value[i]);
	}

	neck_table_can[0]=1;

	for(i=0;i<neck_num;i++) {
		for(j=3999;j>=0;j--) {
			if(neck_table_can[j]==1){
				if( neck_table_value[   j+neck_weight[i]   ] < neck_table_value[j]+neck_value[i]) {
					neck_table_value[   j+neck_weight[i]   ] = neck_table_value[j]+neck_value[i];
					neck_table_can  [   j+neck_weight[i]   ] = 1;
				}
			}
		}
	}
	
	for(i=0;i<=wei_limit;i++) {
		if(neck_table_value[i]>ans) ans=neck_table_value[i];
	}

	printf("%d",ans);
	
	return 0;
}