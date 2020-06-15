#include<stdio.h>

int main() {

	int input;
	scanf("%d", &input);

	int a = input - 1, b = 1;

	bool ok = false;
	for (int i = 0; i < input * 2 - 1; i++) {
		for (int j = 0; j < a; j++) {
			printf(" ");
		}
		for (int j = 0; j < b; j++) {
			printf("*");
		}
		if (!ok) {
			a--;
			b++;
			if (b == input) {
				ok = true;
			}
		}
		else {
			a++;
			b--;
		}
		printf("\n");
	}

	return 0;
}