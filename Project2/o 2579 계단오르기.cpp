#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[300];
int dp[300];

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	dp[0] = map[0];
	dp[1] = max(map[1], map[1] + map[0]);
	dp[2] = max(map[2] + map[0], map[1] + map[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(map[i] + dp[i - 2], map[i] + map[i - 1] + dp[i - 3]);
	}

	cout << dp[n - 1] << endl;

	return 0;
}