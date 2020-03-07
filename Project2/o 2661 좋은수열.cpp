#include<iostream>

using namespace std;

int n;
int map[81], ncount = 1;
static bool gg = false;

void dfs(int cur, int cnt) {
	if (cnt == n) {
		for (int i = 1; i <= n; i++) {
			cout << map[i];
		}
		cout << endl;

		gg = true;

		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (i != cur) {
			map[ncount] = i;

			int yes;
			bool ok = false;
			for (int j = 1; j <= ncount / 2; j++) {
				yes = 0;
				for (int k = 0; k < j; k++) {
					if (map[ncount - k] == map[ncount - j - k]) {
						yes++;
					}
				}
				if (yes == j) {
					ok = true;
				}
			}
			if (ok)
				continue;
			ncount++;
			dfs(i, cnt + 1);
			if (gg)
				return;
			ncount--;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	dfs(0, 0);

	return 0;
}