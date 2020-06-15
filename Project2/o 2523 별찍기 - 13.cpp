#include<stdio.h>

int main() {

	int input;
	scanf("%d", &input);

	int b = 1;

	bool ok = false;
	for (int i = 0; i < input * 2 - 1; i++) {
		for (int j = 0; j < b; j++) {
			printf("*");
		}
		if (!ok) {
			b++;
			if (b == input) {
				ok = true;
			}
		}
		else {
			b--;
		}
		printf("\n");
	}
	return 0;
}