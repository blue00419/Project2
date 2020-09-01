#include <iostream>
#include<algorithm>

using namespace std;


int main() {
	int n;
	cin >> n;

	int* map = new int[n + 1];
	int* dp = new int[n + 1];

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	map[n] = 0;
	dp[0] = map[0];
	dp[1] = min(dp[0] + map[1], map[1]);
	dp[2] = min(dp[1] + map[2], min(dp[0] + map[2], map[2]));

	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 3] + map[i], min(dp[i - 2] + map[i], dp[i - 1] + map[i]));
	}

	cout << dp[n] << endl;


	return 0;
}