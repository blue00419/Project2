#include<stdio.h>

bool map[1001];

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int result = 0;
	for (int i = 2; i <= n; i++) {
		if (map[i] == 0) {
			for (int j = i; j <= n; j += i) {
				if (map[j] == 0) {
					map[j] = 1;
					result++;
					if (result == k) {
						printf("%d\n", j);
					}
				}
			}
		}
	}
	return 0;
}