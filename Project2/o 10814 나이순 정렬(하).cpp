#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef pair<int, string> pi;

bool compare(const pi& a, const pi& b) {
	if (a.first < b.first)
		return true;
	return false;
}

int main() {
	int n;
	cin >> n;

	vector<pi> v;

	int temp;
	string str;
	for (int ii = 0; ii < n; ii++) {
		cin >> temp >> str;
		v.push_back({ temp, str });
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
}