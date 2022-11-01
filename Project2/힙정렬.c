#include<stdio.h>

#define MAX 101

int heap[MAX];
int index = 1;


int main() {

	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		heap[index] = a;

		int b = index;
		while (1) {
			int p = b / 2;
			if (p == 0) break;
			if (heap[p] < heap[b]) {
				int tmp = heap[p];
				heap[p] = heap[b];
				heap[b] = tmp;
				b = p;
			}
			else break;
		}
		index++;
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", heap[i]);
	}


	return 0;
}