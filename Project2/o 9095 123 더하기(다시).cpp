#include<iostream>

using namespace std;

static int counter;

void bfs(int sum, int n) {
	if (sum == n) {
		counter++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (sum + i <= n) {
			bfs(sum + i, n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		counter = 0;
		bfs(0, n);
		cout << counter << '\n';
	}

	return 0;
}