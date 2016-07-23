#include <stdio.h>

int main() {

	freopen("input.txt","r",stdin);

	int flower_home, flower_buy;
	int home[10000], buy[10000];
	int i,j, eat;

	while(1) {
		eat=0;
		scanf("%d %d",&flower_home,&flower_buy);

		if(flower_buy==0 && flower_home==0)
			break;

		for(i=0;i<flower_home;i++)
			scanf("%d",&home[i]);

		for(i=0;i<flower_buy;i++)
			scanf("%d",&buy[i]);

		for(i=0, j=0;i<flower_buy && j<flower_home;) {
			if(buy[i]<home[j]) {
				j++;
			}
			else if(buy[i]>home[j]) {
				i++;
			}
			else {
				eat++;
				i++;
				j++;
			}
		}
		printf("%d\n",eat);

	}
	return 0;
}