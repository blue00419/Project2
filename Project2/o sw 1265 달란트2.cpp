#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		long long n, p;
		cin >> n >> p;

		vector<long long> v;

		long long cost,count;

		v.clear();
		cost = n / p;
		count = 0;

		for (int j = 0; j < p; j++) {
			v.push_back(cost);
			count += cost;
		}
		count = n - count;
		for (int j = 0; j < count; j++) {
			v[j]++;
		}
		long long sum = 1;
		for (int j = 0; j < v.size(); j++) {
			sum *= v[j];
		}

		cout << "#" << ii << " " << sum << endl;
	}

	return 0;
}