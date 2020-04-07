#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		int sum = 0, a;
		char temp;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				cin >> a;
				sum += a;
			}
			else {
				cin >> temp;
			}
		}

		cout << "#" << ii << " " << sum << endl;
	}

	return 0;
}