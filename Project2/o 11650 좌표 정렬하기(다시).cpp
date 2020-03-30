#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

bool compare(pi& a, pi& b) {
	if (a.first < b.first)
		return true;
	if (a.first == b.first)
		return a.second < b.second;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pi> v;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}