#include <stdio.h>

int s[401][801], max_sum, n;
void test_sum(int line, int left, int right, int sum) {
	if (line < 0 || line >= n)
		return;
	if (left <= 0 || right > 1 + (line * 2))
		return;

	sum += s[line][right] - s[line][left - 1];

	if (sum > max_sum)
		max_sum = sum;

	printf("%d & %d = %d\n", left, 1, left & 1);

	if (!(left & 1))
		test_sum(line - 1, left - 2, right, sum);
	else
		test_sum(line + 1, left, right + 2, sum);
}


int main(void) {

	freopen("input.txt", "r", stdin);

	for (int i = 0; i < 401; ++i)
		s[i][0] = 0;

	for (int cnum = 0;1;) {
		scanf("%d", &n);

		if(n == 0)
			break;

		max_sum = -2000000000;

		for (int i = 0, l; i < n; ++i) {
			l = (i*2) + 1;
			for (int j = 1; j <= l; ++j) {
				scanf("%d", &s[i][j]);
				s[i][j] += s[i][j - 1];
			}
		}

		for (int i = 0, l; i < n; ++i) {
			l = (i << 1) + 1;
			for (int j = 1; j <= l; ++j)
				test_sum(i, j, j, 0);
		}

		printf("%d. %d\n", ++cnum, max_sum);
	}
	return 0;
}