#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	long long max = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		if (a > max) {
			max = a;
		}
	}

	long long left = 1, right = max * m, mid, count, result = right;
	while (left <= right) {
		mid = (left + right) / 2;

		count = 0;
		for (int i = 0; i < n; i++) {
			count += mid / v[i];
		}
		if (count >= m) {
			if (result > mid) {
				result = mid;
			}
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << result << endl;

	return 0;
}