#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* map = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int a;
	cin >> a;

	int left = 0, right = n - 1;

	int mid;
	while (1) {
		mid = (left + right) / 2;

		if (left == mid) {
			cout << "X" << endl;
			break;
		}

		if (map[mid] == a) {
			cout << mid + 1 << endl;
			break;
		}
		else if (map[mid] < a) {
			left = mid;
		}
		else if (map[mid] > a) {
			right = mid;
		}
	}

	return 0;
}