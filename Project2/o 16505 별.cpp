#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	int input;

	scanf("%d", &input);

	int num = 1;

	for (int i = 0; i < input; i++) {
		num *= 2;
	}

	char** map = (char**)malloc(sizeof(char*) * num);
	for (int i = 0; i < num; i++) {
		map[i] = (char*)malloc(sizeof(char) * num);
		for (int j = 0; j < num; j++) {
			map[i][j] = ' ';
		}
	}
	int right = 0, down = 0;
	map[0][0] = '*';

	int row, col;
	for (int ii = 0; ii < input; ii++) {
		col = right + 1;
		row = down + 1;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == '*') {
					map[i][j + right + 1] = '*';
					map[i + down + 1][j] = '*';
				}
			}
		}
		right += col;
		down += row;
	}

	for (int i = 0; i < right+1; i++) {
		for (int j = 0; j < down+1 && j < num; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
		num--;
	}

	return 0;
}