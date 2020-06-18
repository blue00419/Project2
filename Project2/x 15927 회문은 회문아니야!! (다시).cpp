#include<stdio.h>
#include<string.h>

char input[500001];

int main() {
	scanf("%s", input);

	int result = -1;
	int size = strlen(input);

	bool ok1 = true;
	int left, right;
	for (int i = 0; i < size; i++) {
		left = i;
		right = size - 1 - i;
		if (left >= right) break;
		if (input[left] != input[right]) {
			ok1 = false;
			break;
		}
		left++;
		right--;
	}

	bool ok2 = true;
	for (int i = 0; i < size; i++) {
		left = i;
		right = size - 2 - i;
		if (left >= right) break;
		if (input[left] != input[right]) {
			ok2 = false;
			break;
		}
		left++;
		right--;
	}

	if (ok1) {
		if (ok2) {
			printf("%d\n", -1);
		}
		else {
			printf("%d\n", size - 1);
		}
	}
	else {
		printf("%d\n", size);
	}

	return 0;
}