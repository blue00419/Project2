#include<stdio.h>
#include<stdlib.h>


int main() {

	int input;
	scanf("%d", &input);
	
	char** map = (char**)malloc(sizeof(char*) * input);
	for (int i = 0; i < input; i++) {
		map[i] = (char*)malloc(sizeof(char) * input);
		for (int j = 0; j < input; j++) {
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)continue;
			map[i][j] = '*';
		}
	}

	int a = input, index = 0;

	while (1) {
		if (a == 3) break;
		index++;
		a /= 3;
	}
	int row = 3, col = 3;
	for (int t = 0; t < index; t++) {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 0 && j == 0) continue;
				if (i == 1 && j == 1) continue;

				for (int ii = 0; ii < row; ii++) {
					for (int jj = 0; jj < col; jj++) {
						if (map[ii][jj] == '*') {
							map[ii + (i*row)][jj + (j*col)] = '*';
						}
					}
				}
			}
		}
		row *= 3;
		col *= 3;
	}
	
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}