#include<iostream>

using namespace std;

void dfs(int cnt, int sum, int a, int b, int ii) {
	if (cnt == b) {
		cout << "#" << ii << " " << sum << endl;
		return;
	}
	dfs(cnt + 1, sum * a, a, b, ii);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;
	int a, b;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;
		cin >> a >> b;
		dfs(0, 1, a, b, ii);
	}

	return 0;
}