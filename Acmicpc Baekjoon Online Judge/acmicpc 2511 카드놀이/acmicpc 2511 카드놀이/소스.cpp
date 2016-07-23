#include <stdio.h>


int main() {
	
	int A[10],B[10];
	int A_score=0, B_score=0;

	int i;

	for(i=0;i<10;i++) scanf("%d",&A[i]);
	for(i=0;i<10;i++) scanf("%d",&B[i]);

	for(i=0;i<10;i++) {
		if(A[i]>B[i]) A_score+=3;
		else if(A[i]==B[i]) {
			A_score++;
			B_score++;
		}
		else if(A[i]<B[i]) B_score+=3;
	}

	printf("%d %d\n",A_score,B_score);
	if(A_score>B_score) printf("%c",'A');
	else if(A_score<B_score) printf("%c",'B');
	else {
		for(i=9;i>=0;i--) {
			if(A[i]>B[i]){
				printf("%c",'A');
				break;
			}
			else if(A[i]<B[i]){
				printf("%c",'B');
				break;
			}
		}
		if(i==-1) printf("%c",'D');
	}

	return 0;

}