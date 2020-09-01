#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int result = 0;

	if (n % 5 == 0) {
		cout << n / 5 << endl;
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		n -= 3;
		if (n < 0) break;
		if (n == 0) {
			cout << i + 1 << endl;
			return 0;
		}
		result++;
		if (n % 5 == 0) {
			result += n / 5;
			cout << result << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}