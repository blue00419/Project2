#include<stdio.h>

int main() {

	int input;
	scanf("%d", &input);

	int index = 1;

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < index; j++) {
			printf("*");
		}
		printf("\n");
		index++;
	}

	return 0;
}