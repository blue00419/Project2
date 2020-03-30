#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	vector<int>::iterator iter = v.begin();

	for (iter; iter != v.end(); iter++) {
		cout << *iter << " ";
	}

	return 0;
}