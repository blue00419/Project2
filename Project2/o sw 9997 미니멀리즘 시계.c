#include<stdio.h>

int main() {

	int t;
	scanf("%d", &t);

	int n;
	for (int ii = 1; ii <= t; ii++) {
		scanf("%d", &n);
		printf("#%d %d %d\n", ii, (2*n) / 60, (2*n) % 60);
	}

	return 0;
}