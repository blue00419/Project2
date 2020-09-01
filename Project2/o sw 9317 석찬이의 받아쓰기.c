#include<stdio.h>

int main() {

	int t;
	scanf("%d", &t);


	for (int ii = 1; ii <= t; ii++) {
		int n;
		scanf("%d", &n);

		char a[100001], b[100001];
		scanf("%s %s", a, b);
		
		int result = n;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				result--;
			}
		}
		printf("#%d %d\n", ii, result);
	}
}