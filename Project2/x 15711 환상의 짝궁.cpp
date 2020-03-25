#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define MAX 2000001

int t;
bool map[MAX];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int rmax = sqrt((double)MAX) + 1.0;

	for (int i = 2; i < rmax; i++) {
		if (map[i] == 0) {
			for (int j = i + i; j < MAX; j = j + i)
				map[j] = 1;
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (map[i] == 0) {
			v.push_back(i);
		}
	}

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
		for (int j = 0; j < (int)v.size() && (long long)v[j] * v[j] <= a; j++) {
			if (a % v[j] == 0) {
				ok = true;
				break;
			}
		}

		if (ok) cout << "NO" << '\n';
		else cout << "YES" << '\n';

	}


	return 0;
}