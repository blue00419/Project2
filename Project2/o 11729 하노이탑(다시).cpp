#include<iostream>

using namespace std;

void hanoi(int cnt, int from, int by, int to) {
	if (cnt == 1) {
		cout << from << " " << to << '\n';
		return;
	}
	else {
		hanoi(cnt - 1, from, to, by);
		cout << from << " " << to << '\n';
		hanoi(cnt - 1, by, from, to);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a = 1;
	for (int i = 0; i < n; i++) {
		a *= 2;
	}
	a--;
	cout << a << '\n';

	hanoi(n, 1, 2, 3);

	return 0;
}