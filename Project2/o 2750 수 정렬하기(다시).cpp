#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<int> map;

	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		map.push_back(a);
	}

	sort(map.begin(), map.end());
	for (int i = 0; i < n; i++) {
		cout << map[i] << endl;
	}

	return 0;
}