#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAX 500+1

int map[MAX];
int dp[MAX];
int sum[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int k;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;

		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));

		for (int j = 1; j <= k; j++) {
			cin >> map[j];
			sum[j] += sum[j - 1] + map[j];
		}

		dp[1] = map[1];
		dp[2] = map[1] + map[2];
		dp[3] = min(dp[2] + sum[2] + map[3], sum[3] - map[2] - map[3] + 2 * (map[2] + map[3]));

		for (int i = 4; i <= k; i++) {
			dp[i] = min(dp[i - 1] + sum[i - 1] + map[i],
				sum[i] - map[i] - map[i - 1] + dp[i - 2] + 2 * (map[i - 1] + map[i]));
			cout << dp[i] << endl;
		}
		// 70 30 40 70 30 50 30 50
		cout << dp[k] << endl;
	}



	return 0;
}