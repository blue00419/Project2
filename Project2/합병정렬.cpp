#include<iostream>

using namespace std;

int temp[50000];

void sort(int list[], int left, int mid, int right) {
	int l, r, k;
	l = left;
	k = left;
	r = mid + 1;

	while (l <= mid && r <= right) {
		if (list[l] <= list[r]) {
			temp[k++] = list[l++];
		}
		else {
			temp[k++] = list[r++];
		}
	}

	if (l > mid) {
		for (int i = r; i <= right; i++) {
			temp[k++] = list[i];
		}
	}
	else {
		for (int i = l; i <= mid; i++) {
			temp[k++] = list[i];
		}
	}

	for (int i = left; i <= right; i++) {
		list[i] = temp[i];
	}
}

void merge_sort(int list[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		sort(list, left, mid, right);
	}
}

int main() {
	int n;
	cin >> n;
	int* list = new int[n];

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		list[i] = a;
	}

	merge_sort(list, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << list[i] << " ";
	}

	delete[] list;
	return 0;
}