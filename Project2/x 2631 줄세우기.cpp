#include<iostream>

using namespace std;

#define MAX 200+1

int map[MAX];
int dp[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
		dp[i] = 1;
	}

	dp[1] = 1;
	int max, dpmax=0;
	for (int i = 2; i <= n; i++) {
		max = 0;
		for (int j = i - 1; j > 0; j--) {
			if (map[i] > map[j]) {
				if (dp[j] >= max)
					max = dp[j] + dp[i];
			}
		}
		if(max > 0)
			dp[i] = max;
		if (dpmax < max)
			dpmax = max;
	}

	cout << n - dpmax << endl;

	return 0;
}