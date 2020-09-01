#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>

#define MAX 4000000

bool map[MAX + 1];

int main() {

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (map[i] == 0) {
			for (int j = i + i; j <= MAX; j += i) {
				map[j] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 2; i <= MAX; i++) {
		if (map[i] == 0) {
			sum++;
		}
	}

	int* soo = (int*)malloc(sizeof(int) * sum);
	int index = 0;
	for (int i = 2; i <= MAX; i++) {
		if (map[i] == 0) {
			soo[index] = i;
			index++;
		}
	}
	int n;
	scanf("%d", &n);

	int result = 0;
	int a;
	for (int i = 0; i < sum; i++) {
		if (soo[i] > n) break;
		a = soo[i];
		if (a == n) {
			result++;
			break;
		}
		for (int j = i+1; j < sum; j++) {
			a += soo[j];
			if (a == n) {
				result++;
				break;
			}
			if (a > n) break;
		}
	}
	printf("%d\n", result);

	return 0;
}