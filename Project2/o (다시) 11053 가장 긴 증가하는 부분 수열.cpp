#include<iostream>

using namespace std;

int n;
int map[1000];
int dp[1000] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int max, allmax = 0;
	for (int i = 0; i < n; i++) {
		max = 0;
		for (int j = 0; j < i; j++) {
			if (map[i] > map[j]) {
				if (max < dp[j])
					max = dp[j];
			}
		}
		dp[i] = max + 1;
		if (dp[i] > allmax)
			allmax = dp[i];
	}

	cout << allmax << endl;

	return 0;
}