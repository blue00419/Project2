#include<iostream>

using namespace std;

int map[1001], dp1[1001], dp2[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	dp1[1] = 1;
	int max;
	for (int i = 2; i <= n; i++) {
		max = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (map[i] > map[j] && dp1[j] > max) {
				max = dp1[j];
			}
		}
		max++;
		dp1[i] = max;
	}

	dp2[n] = 1;
	for (int i = n - 1; i > 0; i--) {
		max = 0;
		for (int j = i + 1; j <= n; j++) {
			if (map[i] > map[j] && dp2[j] > max) {
				max = dp2[j];
			}
		}
		max++;
		dp2[i] = max;
	}

	max = 0;
	for (int i = 1; i <= n; i++) {
		if (dp1[i] + dp2[i] > max) {
			max = dp1[i] + dp2[i];
		}
	}
	cout << max - 1 << endl;
	return 0;
}