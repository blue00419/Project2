#include<iostream>
using namespace std;

int map[201];
int visit[1000];

int find(int x) {
	if (x == map[x]) return x;

	int y = find(map[x]);
	map[x] = y;
	return y;
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	map[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		map[i] = i;
	}

	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if (temp == 1) {
				Union(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> visit[i];
	}

	bool ok = true;
	for (int i = 0; i < m - 1; i++) {
		int x = find(visit[i]);
		int y = find(visit[i + 1]);
		if (x != y) {
			ok = false;
		}
	}

	if (ok)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}