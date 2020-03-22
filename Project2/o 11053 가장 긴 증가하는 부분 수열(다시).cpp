#include<iostream>

using namespace std;

#define MAX 1000+1

int n;
int map[MAX], dp[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	dp[1] = 1;

	int max, result=1;
	for (int i = 2; i <= n; i++) {
		max = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (map[i] > map[j] && dp[j] > max) {
				max = dp[j];
			}
		}
		max++;
		dp[i] = max;
		if (result < dp[i])
			result = dp[i];
	}

	cout << result << '\n';

	return 0;
}