#include<stdio.h>

char data[20];

int calc(int cnt, int input) {

	int index = 0;

	while (1) {
		data[index] = input % cnt;
		input /= cnt;
		index++;
		if (input == 0) break;
	}
	return index;
}


int main() {

	int t;
	scanf("%d", &t);

	for (int ii = 0; ii < t; ii++) {
		int input;
		scanf("%d", &input);

		bool ok = true;
		int index;
		for (int i = 2; i <= 64; i++) {
			index = calc(i, input);
			int a = index - 1;

			ok = true;
			for (int j = 0; j < index; j++) {
				if (j >= a) break;
				if (data[j] != data[a]) {
					ok = false;
					break;
				}
				a--;
			}
			if (ok) {
				break;
			}
		}
		if (ok) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}