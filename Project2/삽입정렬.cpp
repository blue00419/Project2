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
		if (i > 0) {
			int index = i - 1;
			while (1) {
				if(map[index] > a) {
					map[index + 1] = map[index];
					map[index] = a;
				}
				else {
					break;
				}
				index--;
				if (index < 0) break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << map[i] << " ";
	}
	cout << endl;


	delete[] map;
	return 0;
}