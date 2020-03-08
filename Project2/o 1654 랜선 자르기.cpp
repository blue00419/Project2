#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long k, n, result = 0;
	long long map[10010];

	long long max = 0;
	cin >> k >> n;
	for (int i = 1; i <= k; i++) {
		cin >> map[i];
		if (max < map[i])
			max = map[i];
	}

	long long left = 1, right = max;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long temp = 0;
		for (int i = 1; i <= k; i++) {
			temp += map[i] / mid;
		}
		if (temp >= n) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result << endl;

	return 0;
}