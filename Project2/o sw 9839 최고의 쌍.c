#include<stdio.h>

int map[1000];
int main() {

	int t;
	scanf("%d", &t);

	for (int ii = 1; ii <= t; ii++) {

		int n;
		scanf("%d", &n);

		int temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			map[i] = temp;
		}

		int result = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = map[i] * map[j];
				int c = a;
				int b = a % 10;
				int ok = 1;
				while (1) {
					a /= 10;
					if (a == 0) break;
					if (b-1 != a % 10) {
						ok = 0;
						break;
					}
					b = a % 10;
				}
				if (ok) {
					if (result < c) {
						result = c;
					}
				}
			}
		}
		if (result == 0) {
			printf("#%d -1\n", ii);
		}
		else {
			printf("#%d %d\n", ii, result);
		}
	}



	return 0;
}