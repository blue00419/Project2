#include<iostream>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int sort(int list[], int left, int right) {
	int pivot = list[left];
	int i = left, j = right;

	while (i < j) {
		while (pivot < list[j]) {
			j--;
		}
		while (i < j && pivot >= list[i]) {
			i++;
		}
		swap(list[i], list[j]);
	}
	list[left] = list[i];
	list[i] = pivot;

	return i;
}

void quicksort(int list[], int left, int right) {
	if (left >= right) return;

	int pivot = sort(list, left, right);

	quicksort(list, left, pivot - 1);
	quicksort(list, pivot + 1, right);
}

int main() {
	int n;
	cin >> n;

	int* map = new int[n];
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		map[i] = a;
	}

	quicksort(map, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << map[i] << " ";
	}

	delete[] map;
	return 0;
}