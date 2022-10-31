#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* map = new int[n];

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		map[i] = a;
	}

	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		bool ok = true;
		for (int j = 0; j < i; j++) {
			if (map[j] > map[j + 1]) {
				int tmp = map[j];
				map[j] = map[j + 1];
				map[j + 1] = tmp;
				count++;
				ok = false;
			}
		}
		if (ok) break;
	}
	printf("%d\n", count);

	delete[] map;
	return 0;
}