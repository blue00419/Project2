#include<iostream>

using namespace std;

#define MAX 100+1

int n, m;
int dp[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 0x3f3f3f3f;
			if (i == j)
				dp[i][j] = 0;
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		if (dp[a][b] > c)
			dp[a][b] = c;
	}

	for (int i = 1; i <= n; i++) { // 거쳐갈 정점
		for (int j = 1; j <= n; j++) { // 출발 정점
			for (int k = 1; k <= n; k++) { // 도착 정점
				if (dp[j][i] + dp[i][k] < dp[j][k])
					dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == 0x3f3f3f3f)
				cout << 0 << " ";
			else
				cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}