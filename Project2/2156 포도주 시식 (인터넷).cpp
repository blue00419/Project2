#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[10001] = { 0, };
int dp[10001] = { 0, };

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	dp[1] = map[1];
	dp[2] = map[1] + map[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + map[i], 
			map[i] + map[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i - 1], dp[i]); 
	}
	cout << dp[n] << endl;

	return 0;
}