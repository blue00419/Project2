#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	while (1) {
		if (n == 1) break;

		int a = 2;
		while (1) {
			if (n % a == 0) {
				n /= a;
				cout << a << endl;
				break;
			}
			a++;
		}
	}
	return 0;
}