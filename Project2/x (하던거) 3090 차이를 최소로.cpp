#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

long long n, t, temp;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long max = 0;

	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		if (max < temp)
			max = temp;
	}

	long long left = 1, right = max, mid, result = 0, count;
	while (left <= right) {
		mid = (left + right) / 2;

		cout << endl;
		count = 0;
		for (int i = 0; i < n - 1; i++) { // 차이 배열 만들어서 해보자
			if (abs(v[i] - v[i + 1]) / mid >= 1) {
				count += (abs(v[i] - v[i + 1]) / mid) - 1;
				cout << i << " " << count << endl;
			}
		}

		cout << mid << " " << count << endl;
		if (count >= t) {
			if (result > mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}


	return 0;
}