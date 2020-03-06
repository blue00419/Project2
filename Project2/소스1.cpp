#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[100000];
int dp[100000];
int allmax = -1000000000;

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	dp[0] = map[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(map[i], map[i] + dp[i - 1]);
		if (dp[i] > allmax) {
			allmax = dp[i];
		}
	}
	cout << allmax << endl;
	return 0;
}