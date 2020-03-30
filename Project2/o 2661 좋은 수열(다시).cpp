#include<iostream>

using namespace std;

#define MAX 80+1

int n;
int map[MAX];

void dfs(int cnt) {
	if (cnt == n+1) {
		for (int i = 1; i <= n; i++) {
			cout << map[i];
		}
		cout << endl;
		exit(0);
	}

	int half;
	for (int i = 1; i <= 3; i++) {
		map[cnt] = i;
		if (cnt == 1) {
			dfs(cnt + 1);
		}
		else {
			half = cnt / 2;
			bool ok = true;
			int count;
			while (1) {
				count = 0;
				for (int i = 0; i < half; i++) {
					if (map[cnt - i] == map[cnt - i - half])
						count++;
				}
				if (count == half) {
					ok = false;
					break;
				}
				half--;
				if (half == 0)
					break;
			}
			if (ok)
				dfs(cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dfs(1);

	return 0;
}