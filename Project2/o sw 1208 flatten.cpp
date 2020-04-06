#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	for (int ii = 1; ii <= t; ii++) {
		v.clear();
		cin >> n;
		int temp;
		for (int i = 0; i < 100; i++) {
			cin >> temp;
			v.push_back(temp);
		}

		for (int i = 0; i < n; i++) {
			sort(v.begin(), v.end());
			v[0]++;
			v[99]--;
		}
		sort(v.begin(), v.end());

		cout << "#" << ii << " " << v[99] - v[0] << '\n';
	}

	return 0;
}