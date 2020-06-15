#include<stdio.h>

int main() {

	int input;
	scanf("%d", &input);

	int a = input - 1, b = 1;
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < a; j++) {
			printf(" ");
		}
		for (int j = 0; j < b; j++) {
			printf("*");
		}
		a--;
		b += 2;
		printf("\n");
	}
}