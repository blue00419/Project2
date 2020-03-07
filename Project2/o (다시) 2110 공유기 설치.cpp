#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, c, temp;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> temp;;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int left = 1, right = v[n - 1], mid, result=0;
	int count;
	while (left <= right) {
		mid = (left + right) / 2;
		count = 1;
		temp = v[0];
		for (int i = 0; i < n; i++) {
			if (v[i] - temp >= mid) {
				count++;
				temp = v[i];
			}
		}

		if (count >= c) {
			result = mid;
			left = mid + 1;
		}
		else 
			right = mid - 1;
	}
	cout << result << '\n';

	return 0;
}