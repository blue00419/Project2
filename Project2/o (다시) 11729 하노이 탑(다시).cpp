#include<iostream>

using namespace std;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		cout << from << " " << to << '\n';
	}
	else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << '\n';
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int hanoinum = 1;
	for (int i = 0; i < n; i++) {
		hanoinum *= 2;
	}
	hanoinum--;

	cout << hanoinum << '\n';

	hanoi(n, 1, 2, 3);

	return 0;
}