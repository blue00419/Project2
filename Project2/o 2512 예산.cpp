#include<iostream>

using namespace std;

int n, m;
int map[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
		if (map[i] > max)
			max = map[i];
	}
	cin >> m;

	int left = 0, right = max, mid, total, result = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		total = 0;
		for (int i = 1; i <= n; i++) {
			if (map[i] > mid) {
				total += mid;
			}
			else {
				total += map[i];
			}
		}

		if (total <= m) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result << '\n';
	return 0;
}