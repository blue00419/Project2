#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a;
	vector<int> v1, v2;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v1.push_back(a);
	}

	sort(v1.begin(), v1.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		v2.push_back(a);
	}

	int b, c;
	for (int i = 0; i < m; i++) {
		b = lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
		c = upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
		cout << c-b << " ";
	}


	return 0;
}