#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000000+1

int map[MAX];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < MAX; i++) {
		if (map[i] == 0) {
			for (int j = i; j < MAX; j = j + i)
				map[j] = 1;
			if (i > 2)
				v.push_back(i);
		}
	}

	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			break;

		bool ok = false;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > n - 3)
				break;
			for (int j = i; j < v.size(); j++) {
				if (v[i] + v[j] > n)
					break;
				if (v[i] + v[j] == n) {
					ok = true;
					cout << n << " = " << v[i] << " + " << v[j] << '\n';
					break;
				}
			}
			if (ok)
				break;
		}

		if (!ok)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}

	return 0;
}