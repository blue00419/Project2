#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

int main() {
	int n;
	cin >> n;

	vector<pi> v;
	vector<int> result;
	int a;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back({ a,i + 1 });
		sum += a;
	}
	sort(v.begin(), v.end());

	sum -= v[n - 1].first;

	for (int i = 0; i < n - 1; i++) {
		if (sum - v[i].first == v[n - 1].first) {
			result.push_back(v[i].second);
		}
	}

	if (sum - v[n - 2].first == v[n - 2].first) {
		result.push_back(v[n - 1].second);
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}

	return 0;
}