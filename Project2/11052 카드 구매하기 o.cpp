#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[1001];
int dp[1001];

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	dp[1] = map[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = map[i];
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n] << endl;

	return 0;
}