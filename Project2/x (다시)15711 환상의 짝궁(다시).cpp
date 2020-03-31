#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

#define MAX 2000000

int map[MAX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int rmax = sqrt((double)MAX) + 1.0;
	for (int i = 2; i <rmax; i++) {
		if (map[i] == 0)
			for (int j = i; j < MAX + 1; j = j + i)
				map[j] = 1;
	}

	vector<int> v;
	for (int i = 2; i < MAX + 1; i++) {
		if (map[i] == 0)
			v.push_back(i);
	}

	int t;
	cin >> t;

	long long a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;

		a += b;
		if (a < 4) {
			cout << "NO" << '\n';
			continue;
		}
		if (a % 2 == 0) {
			cout << "YES" << '\n';
			continue;
		}

		a -= 2;
		bool ok = false;

		for (int j = 0; j < v.size(); j++) {
			if ((long long)v[j] * v[j] > a)
				break;
			if (a % v[j] == 0) {
				ok = true;
				break;
			}
		}

		if (ok)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

	return 0;
}