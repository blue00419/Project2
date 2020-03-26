#include<iostream>

using namespace std;

#define MAX 100+1

int n, m;
bool dp[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dp[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][i] && dp[i][k]) dp[j][k] = 1;
			}
		}
	}

	int count;
	for (int i = 1; i <= n; i++) {
		count = 0;
		for (int j = 1; j <= n; j++) {
			if (!dp[i][j] && !dp[j][i]) count++;
		}
		cout << count - 1 << '\n';
	}

	return 0;
}