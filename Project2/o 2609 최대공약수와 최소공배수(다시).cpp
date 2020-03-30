#include<iostream>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b > 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}

	cout << gcd(a, b) << '\n';
	cout << a * b / gcd(a, b) << '\n';

	return 0;
}