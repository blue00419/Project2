#include<iostream>

using namespace std;

int gbc(int a, int b) {
	int c;
	while (b != 0) {
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	cout << gbc(a, b) << '\n';
	cout << a * b / gbc(a, b) << '\n';

	return 0;
}