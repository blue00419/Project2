#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, c;
vector<int> map;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	int max = 0, temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (max < temp)
			max = temp;
		map.push_back(temp);
	}
	sort(map.begin(), map.end());

	long long left = 1, right = max, mid, result = 0, count, gijun;
	while (left <= right) {
		mid = (left + right) / 2;
		count = 1;
		gijun = map[0];
		for (int i = 1; i < n; i++) {
			if (gijun + mid <= map[i]) {
				count++;
				gijun = map[i];
			}
		}

		if (count >= c) {
			if(result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result << '\n';
	return 0;
}