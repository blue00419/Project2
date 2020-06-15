#include<stdio.h>

int main() {

	int input;
	scanf("%d", &input);

	int a = 0, b = 1;

	for (int i = 0; i < input - 1; i++) {
		b += 2;
	}

	bool ok = false;
	for (int i = 0; i < input * 2 - 1; i++) {
		for (int j = 0; j < a; j++) {
			printf(" ");
		}
		for (int j = 0; j < b; j++) {
			printf("*");
		}
		printf("\n");
		if (!ok) {
			a++;
			b -= 2;
			if (b == 1) {
				ok = true;
			}
		}
		else {
			a--;
			b += 2;
		}
	}


	return 0;
}