#include<stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	int n, k;
	for (int ii = 1; ii <= t; ii++) {
		scanf("%d %d", &n, &k);
		printf("#%d %d\n", ii, (n % k) ? 1 : 0);
	}
	return 0;
}