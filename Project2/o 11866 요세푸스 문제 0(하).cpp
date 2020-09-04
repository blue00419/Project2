#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, bool> pi;

int main() {
	int n, k;
	cin >> n >> k;

	vector<pi> v;
	for (int i = 1; i <= n; i++) {
		v.push_back({ i,1 });
	}

	int index = 0;
	int remove = 0;
	cout << "<";

	int a = 0;
	while (1) {
		if (v[index].second == 1) {
			a++;
		}
		if (a == k) {
			v[index].second = 0;
			remove++;
			a = 0;
			if (remove == n) {
				cout << v[index].first << ">";
				break;
			}
			else {
				cout << v[index].first << ", ";
			}
		}

		index++;
		if (index == n) index = 0;
	}
}
