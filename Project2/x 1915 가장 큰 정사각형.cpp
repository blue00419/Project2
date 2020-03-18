#include<iostream>

using namespace std;

#define MAX 1000+1

int n, m;
int map[MAX][MAX];

int calc(int x, int y, int size) {

	int ok = 0;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (i > 0 && i <= n && j > 0 && j <= m) {
				if (map[i][j] == 1)
					ok++;
			}
		}
	}
	int result = size;
	if (ok == size * size)
		result = calc(x, y, size + 1);
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	char temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	int max = 0, result=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				result = calc(i, j, 2) - 1;
				if (max < result)
					max = result;
			}
		}
	}

	cout << max*max << '\n';

	return 0;
}