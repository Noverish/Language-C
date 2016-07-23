#include <stdio.h>


int main() {

	int swap, weight1, weight2, measure, now_weight1, now_weight2;
	int answer_w1, answer_w2, I_find_answer=0;
	int i, j;

	while(1) {
	
		scanf("%d %d %d",&weight1,&weight2,&measure);

		if(weight1==0 && weight2==0 && measure==0)
			break;

		now_weight1=weight1;
		now_weight2=weight2;

		for(i=0;now_weight2<measure;i++) {
			if((measure-now_weight2*i)%now_weight1==0) {
				answer_w2=i;
				answer_w1=(measure-now_weight2*i)/now_weight1;
				I_find_answer=1;
				break;
			}
		}

		if(I_find_answer==1) {
			printf("%d %d\n",answer_w1,answer_w2);
			I_find_answer=0;
			break;
		}

		now_weight1=weight1;
		now_weight2=weight2;

		for(;



	}


	return 0;
}