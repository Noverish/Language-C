#include <stdio.h>

int main() {

	int i;
	int sum=0;
	for(i=1;i<=2000;i++)
		sum+=i;

	printf("%d",sum);

	return 0;

}

int main1() {

	//freopen("input.txt","r",stdin);

	int hard_core[1004];
	int test_case, answer=0, add, max_chapter=0, max=0;
	int left, right;
	int i;

	scanf("%d",&test_case);



	for(i=0;i<test_case;i++) 
		scanf("%d",&hard_core[i]);

	for(i=0;i<test_case;i++) {
		if(max<hard_core[i]) {
			max=hard_core[i];
			max_chapter=i;
		}
	}

	add=test_case;
	answer+=hard_core[max_chapter];
	if(max_chapter==0)

	for(;1;add--) {
		
	}

	printf("%d",answer);

	return 0;
}