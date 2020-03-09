#include<iostream>
#include<vector>

using namespace std;

long long n, m, temp; // 심사대, 친구수
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long max = 0;

	cin >> n >> m; // 심사대, 친구수
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		if (max < temp)
			max = temp;
	}

	long long left = 1, right = max*m, mid, result = right, count;
	while (left <= right) {
		mid = (left + right) / 2;

		count = 0;
		for (int i = 0; i < n; i++) {
			count += mid / v[i];
		}
		if (count >= m) {
			if(result > mid)
				result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << result << endl;

	return 0;
}