#include<iostream>

using namespace std;

#define MAX 15

bool map[MAX][MAX];
static int counter = 0;

void dfs(int cnt,int n) {
	if (cnt == n) {
		counter++;
		return;
	}

	bool ok;
	for (int j = 0; j < n; j++) {
		if (map[cnt][j] == 0) {
			ok = true;
			for (int k = 1; k<= cnt; k++) {
				if (map[cnt - k][j] == 1)
					ok = false;
				if (j - k >= 0) {
					if (map[cnt - k][j - k] == 1)
						ok = false;
				}
				if (j + k < n) {
					if (map[cnt - k][j + k] == 1)
						ok = false;
				}
			}

			if (ok) {
				map[cnt][j] = 1;
				dfs(cnt + 1, n);
				map[cnt][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dfs(0,n);
	cout << counter << endl;

	return 0;
}