#include<stdio.h>

#define MAX 100

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);

	int map[MAX] = { 0, };

	for (int i = 0; i < n; i++) {
		int a;
		scanf_s("%d", &a);
		map[i] = a;
	}

	int s=0, e=0;
	int sum = map[0];
	int count = 0;
	while (1) {
		if (sum < m) {
			e++;
			if (e == n) break;
			sum += map[e];
		}
		else if (sum > m) {
			s++;
			if (s == n) break;
			sum -= map[s - 1];
		}
		else {
			count++;
			s++;
			if (s == n)break;
			sum -= map[s - 1];
		}
	}
	printf("%d\n", count);



	return 0;
}