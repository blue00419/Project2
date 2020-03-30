#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	vector<int> v, vv;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		vv.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		cout << binary_search(v.begin(), v.end(), vv[i]) << " ";
	}

	return 0;
}