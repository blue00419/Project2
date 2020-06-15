#include<stdio.h>
#include<stdlib.h>

int main() {

	int input;
	scanf("%d", &input);

	char** map = (char**)malloc(sizeof(char*) * input);
	for (int i = 0; i < input; i++) {
		map[i] = (char*)malloc(sizeof(char) * (input * 2 - 1));
		for (int j = 0; j < (input * 2 - 1); j++) {
			map[i][j] = ' ';
		}
	}

	int a = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if ((j + 1) % a == 0) {
				map[i][j] = '*';
			}
		}
		a++;
	}

	a = input;
	a /= 3;
	int index = 0;

	while (1) {
		a /= 2;
		if (a == 0)break;
		index++;
	}

	int row = 3, col = 5, half;
	for (int t = 0; t < index; t++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == '*') {
					map[i][j + col + 1] = '*';
				}
			}
		}

		half = col / 2;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == '*') {
					map[i + row][j + half + 1] = '*';
				}
			}
		}
		row *= 2;
		col *= 2;
		col++;
	}

	for (int i = input-1; i >=0; i--) {
		for (int j = 0; j < input * 2 - 1; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}