#include<iostream>

using namespace std;

#define MAX 1000000+1

int map[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map[0] = 1;
	map[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (map[i] == 0) {
			for (int j = i + i; j < MAX; j = j + i)
				map[j] = 1;
		}
	}

	int m, n;

	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (map[i] == 0)
			cout << i << '\n';
	}

	return 0;
}