#include<iostream>

using namespace std;

#define MAX 1000+1
int n, k;
double dp[MAX][MAX] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 0; i <= k; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	cout << dp[n][k] << endl;

	return 0;
}