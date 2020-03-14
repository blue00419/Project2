#include<iostream>
using namespace std;

int map[1000000 + 1];

int find(int x) {
	if (x == map[x]) return x;
	int y = find(map[x]);
	map[x] = y;
	return find(map[x]);
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

	for (int i = 0; i <= n; i++) {
		map[i]= i;
	}

	int x, a, b;
	for (int i = 0; i < m; i++) {
		cin >> x >> a >> b;

		if (x == 0) {
			Union(a, b);
		}
		else {
			int ap = find(a);
			int bp = find(b);
			if (ap == bp)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}