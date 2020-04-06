#include<iostream>

using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	float p, q;
	for (int i = 1; i <= t; i++) {
		cin >> p >> q;

		float s1, s2;
		s1 = (1 - p) * q;
		s2 = p * (1 - q) * q;

		if (s1 < s2) {
			cout << "#" << i << " " << "YES" << endl;
		}
		else {
			cout << "#" << i << " " << "NO" << endl;
		}
	}


	return 0;
}