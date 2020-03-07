#include<iostream>

using namespace std;

long long n, m;
long long map[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long max = 0, result = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
		if (max < map[i])
			max = map[i];
	}

	long long left = 0, right = max, mid, temp;
	while (left <= right) {
		mid = (left + right) / 2;
		temp = 0;
		
		for (int i = 1; i <= n; i++) {
			if (map[i] > mid) {
				temp += map[i] - mid;
			}
		}

		if (temp >= m) {
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