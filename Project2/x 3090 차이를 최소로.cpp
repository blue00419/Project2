#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define MAX 100000+1

int n, t, v[MAX], cv[MAX];

bool calc(int mid) {

	int count = 0;
	for (int i = 0; i < n; i++) {
		cv[i] = v[i];
		if (i != 0) {
			if (cv[i - 1] - cv[i] > mid&& cv[i - 1] - (cv[i - 1] - cv[i] - mid) > 1) {
				count += cv[i - 1] - cv[i] - mid;
				cv[i - 1] -= cv[i - 1] - cv[i] - mid;

				if (count > t) {
					return false;
				}
			}
			if (cv[i] - cv[i - 1] > mid&& cv[i] - (cv[i] - cv[i - 1] - mid) > 1) {
				count += cv[i] - cv[i - 1] - mid;
				cv[i] -= cv[i] - cv[i - 1] - mid;

				if (count > t) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int left = 1, right = MAX, mid, min = MAX;
	while (left <= right) {
		mid = (left + right) / 2;

		if (calc(mid)) {
			if (min > mid)
				min = mid;
			right = mid - 1;
		}
		else
			left = mid - 1;
	}
	calc(min);
	for (int i = 0; i < n; i++) {
		cout << cv[i] << " ";
	}
	cout << endl;

	return 0;
}