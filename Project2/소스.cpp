#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int dp[10001] = { 0, };
	int* coins = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			if (j - coins[i] >= 0) {
				dp[j] += dp[j - coins[i]];
				cout << dp[j] << endl;
			}
		}
	} // 동전 시일패 다음거하면됨

	cout << dp[k] << endl;
	return 0;
}