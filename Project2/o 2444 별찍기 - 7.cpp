#include<stdio.h>

int main() {

	int input;
	scanf("%d", &input);

	int a = input - 1, b = 1;

	bool ok = false;
	for (int i = 0; i < 2*input - 1; i++) {
		for (int j = 0; j < a; j++) {
			printf(" ");
		}
		for (int j = 0; j < b; j++) {
			printf("*");
		}
		printf("\n");
		if (!ok) {
			a--;
			b+=2;
			if (a == 0) {
				ok = true;
			}
		}
		else {
			a++;
			b -= 2;
		}
	}

	return 0;
}