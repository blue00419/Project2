#include<stdio.h>


int main() {

	int t;
	scanf("%d", &t);

	for (int ii = 1; ii <= t; ii++) {
		int n;
		scanf("%d", &n);

		int map[12];
		for (int i = 0; i < 12; i++) {
			map[i] = 4;
		}
		map[10] = 16;

		int temp;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			sum += temp;
			map[temp]--;
		}
		sum = 21 - sum;

		int stop = 0, go = 0;
		for (int i = 2; i < 12; i++) {
			if (i <= sum) {
				go += map[i];
			}
			else {
				stop += map[i];
			}
		}

		if (go > stop) {
			printf("#%d GAZUA\n", ii);
		}
		else {
			printf("#%d STOP\n", ii);
		}

	}


	return 0;
}