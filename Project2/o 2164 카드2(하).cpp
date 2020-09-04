#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	int a = 2;
	for (int i = 2; i <= n; i++) {
		if (i < a + 2) {
			a = 2;
		}
		else {
			a += 2;
		}
	}
	cout << a << endl;
}