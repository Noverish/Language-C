#include <stdio.h>

int main() {

	int matrixNum;

	scanf("%d",&matrixNum);

        int p[1000];

        for(int i = 0;i<matrixNum;i++) {
            int tmp;

            if(i == 0) {
				scanf("%d",&p[0]);
				scanf("%d",&p[1]);
            }
            else {
				scanf("%d",&tmp);
				scanf("%d",&p[i + 1]);
            }

        }

        int n = matrixNum-2;
        int m[1000][1000];
        int s[1000][1000];

        for (int ii = 1; ii < n; ii++) {
            for (int i = 0; i < n - ii; i++) {
                int j = i + ii;
                m[i][j] = 0x7fffffff;
                for (int k = i; k < j; k++) {
                    int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }

		int a = 0;

	return 0;
}