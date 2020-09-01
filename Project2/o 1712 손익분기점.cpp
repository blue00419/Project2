#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b >= c) {
		cout << -1 << endl;
		return 0;
	}

	c -= b;
	int result = a / c + 1;
	cout << result << endl;

	return 0;
}