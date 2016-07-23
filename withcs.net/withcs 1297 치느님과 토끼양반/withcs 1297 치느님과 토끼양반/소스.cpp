#include <stdio.h>

int main() {

	int test_case;
	int min_ani, max_ani;
	int ani_leg;


	scanf("%d",&test_case);

	for(;test_case>0;test_case--) {

		scanf("%d",&ani_leg);

		if(ani_leg%2==0){
			if(ani_leg%4==0){
				min_ani=ani_leg/4;
				max_ani=ani_leg/2;
			}
			else{
				min_ani=(ani_leg/4)+1;
				max_ani=(ani_leg/2);
			}
		}
		else{
			min_ani=max_ani=0;
		}

		printf("%d %d\n",min_ani,max_ani);


		
	}

	return 0;
}