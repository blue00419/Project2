#include<iostream>

using namespace std;

#define MAX 100+1

int n;
int map[MAX][MAX];
int dp[MAX][MAX] = { 0, };

int calc(int x, int y) {

	if (x > n || y > n) return 0;
	if (x == n && y == n) return 1;
	if (dp[x][y] != 0) return dp[x][y];
	return dp[x][y] = calc(x + map[x][y], y) + calc(x, y + map[x][y]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	printf("%d\n", calc(1, 1));

	return 0;
}