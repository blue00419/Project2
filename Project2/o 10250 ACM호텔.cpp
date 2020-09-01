#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int ii = 0; ii < t; ii++) {
		int h, w, n;
		cin >> h >> w >> n;

		int result = n / h;
		if (n % h != 0) {
			result++;
		}

		while (1) {
			if (n <= h) break;

			n -= h;
		}

		n *= 100;
		result += n;
		cout << result << endl;
	}
	return 0;
}