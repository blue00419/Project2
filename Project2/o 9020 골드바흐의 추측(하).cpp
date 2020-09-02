#include<iostream>
#include<vector>

using namespace std;

int map[10001];

int main() {
	int t;
	cin >> t;

	for (int i = 2; i <= 100; i++) {
		if (map[i] == 0) {
			for (int j = i+i; j <= 10000; j += i) {
				map[j] = 1;
			}
		}
	}

	vector<int> v;

	for (int i = 2; i <= 10000; i++) {
		if (map[i] == 0) {
			v.push_back(i);
		}
	}

	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;

		int a, b;
		a = n / 2;
		b = a;
		bool aok, bok;
		while (1) {
			aok = false;
			bok = false;

			for (int i = 0; i < v.size(); i++) {
				if (v[i] == a) {
					aok = true;
				}
				if (v[i] == b) {
					bok = true;
				}
				if (aok && bok) {
					cout << a << " " << b << endl;
					break;
				}
				if (v[i] > b) {
					break;
				}
				if (v[i] > a&& aok == false) {
					break;
				}
			}
			if (aok && bok) break;
			a--;
			b++;
		}
	}

	return 0;
}