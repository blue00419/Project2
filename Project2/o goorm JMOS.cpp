#include <iostream>

using namespace std;

int n;
int map[1000];
int dp[1000];

int main() {

	cin >> n;

	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		dp[i] = 1;
		int a = 0;
		for (int j = 0; j < i; j++) {
			if (map[j] < map[i]) {
				if (a < dp[j]) {
					a = dp[j];
				}
			}
		}
		dp[i] += a;
		if (dp[i] > max) {
			max = dp[i];
		}
	}

	cout << n - max << endl;
	return 0;
}