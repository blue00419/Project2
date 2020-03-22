#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 10000+1

int n;
int map[MAX];
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	dp[1] = map[1];
	dp[2] = map[1] + map[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], max(map[i] + map[i - 1] + dp[i - 3], map[i] + dp[i - 2]));
	}

	cout << dp[n] << '\n';

	return 0;
}