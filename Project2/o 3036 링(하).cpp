#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	vector<int> re;

	int b = v[0];
	while (1) {
		int a = 2;

		while (1) {
			if (b % a == 0) {
				re.push_back(a);
				b /= a;
				break;
			}
			a++;
		}

		if (b == 1) break;
	}

	for (int i = 1; i < n; i++) {
		b = v[0];
		for (int j = 0; j < re.size(); j++) {
			if (v[i] % re[j] == 0) {
				b /= re[j];
				v[i] /= re[j];
			}
		}

		cout << b << "/" << v[i] << endl;
	}
}