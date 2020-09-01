#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool map[100001];

int main() {

	int t;
	scanf("%d", &t);

	int n;
	for (int ii = 1; ii <= t; ii++) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			map[i] = 0;
		}

		int temp;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (map[temp] == 0) {
				map[temp] = 1;
			}
			else {
				ok = false;
			}
		}
		if (ok) {
			printf("#%d Yes\n", ii);
		}
		else {
			printf("#%d No\n", ii);
		}
	}

	return 0;
}