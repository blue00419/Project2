#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 1000+1

int n, m;
int map[MAX][MAX];

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

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				map[i][j] = min(map[i - 1][j], min(map[i][j - 1], map[i - 1][j - 1])) + 1;
				if (result < map[i][j])
					result = map[i][j];
			}
		}
	}
	cout << result*result << '\n';

	return 0;
}