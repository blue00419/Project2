#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;
		v.clear();

		char temp = '0';
		int a, b;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				cin >> a;
				if (temp == '*') {
					a = a * b;
				}
			}
			else {
				cin >> temp;
				if (temp == '+') {
					v.push_back(a);
				}
				else {
					b = a;
				}
			}
		}
		v.push_back(a);

		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}

		cout << "#" << ii << " " << sum << endl;
	}

	return 0;
}