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

	for (int i = 0; i < n - 1; i++) {
		int min = 10000;
		int index;
		for (int j = i + 1; j < n; j++) {
			if (map[i] > map[j]) {
				if (min > map[j]) {
					min = map[j];
					index = j;
				}
			}
		}
		if (map[i] > min) {
			int tmp = map[i];
			map[i] = min;
			map[index] = tmp;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << map[i] << " ";
	}

	cout << endl;

	delete[] map;
	return 0;

}