#include <stdio.h>

int main() {

	int martix_a[100][100], martix_b[100][100], martix_ans[100][100];
	int N, M, K;
	int i, j;

	scanf("%d %d",&N,&M);

	for(i=0;i<N;i++) {
		for(j=0;j<M;j++) {
			scanf("%d",&martix_a[i][j]);
		}
	}

	scanf("%d %d",&M,&K);

	for(i=0;i<M;i++) {
		for(j=0;j<K;j++) {
			scanf("%d",&martix_b[i][j]);
		}
	}

	for(i=0;i<M;i++) {
		for(j=0;j<K;j++) {

		}
	}

	return 0;
}