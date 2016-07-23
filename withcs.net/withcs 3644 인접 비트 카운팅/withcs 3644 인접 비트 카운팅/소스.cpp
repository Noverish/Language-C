#include<stdio.h>

int zero_end[200][200], one_end[200][200];


main() {

	int n, p;
	int test_case, pro_num, bit_num, adjbc;

	scanf("%d",&test_case);

	
	zero_end[1][0]=one_end[1][0]=1;

	

	for(n=2;n<110;n++) {
		for(p=0;p<n;p++) {
			zero_end[n][p] = zero_end[n-1][p] + one_end[n-1][p];
			if(p!=0) one_end[n][p] = zero_end[n-1][p] + one_end[n-1][p-1];
			else one_end[n][p] = zero_end[n-1][p];
		}
	}

	for(pro_num=1;pro_num<=test_case;pro_num++) {

		scanf("%d %d %d",&pro_num,&bit_num,&adjbc);

		printf("%d %d\n",pro_num,zero_end[bit_num][adjbc]+one_end[bit_num][adjbc]);

	}
	return 0;
}