#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int a, b, c, d, f, e;
	double dist;
	int t1, t2;
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c;
		cin >> d >> e >> f;

		bool ok = false;
		if (a == d && b == e) {
			if (c == f) {
				cout << -1 << '\n';
			}
			else
				cout << 0 << '\n';
			ok = true;
		}

		if (ok)
			continue;

		t1 = abs(a - d);
		t2 = abs(b - e);
		t1 = t1 * t1;
		t2 = t2 * t2;
		
		dist = sqrt(t1 + t2);

		if (dist > c + f) {
			cout << 0 << '\n';
		}
		else if (dist == c + f) {
			cout << 1 << '\n';
		}
		else if (dist < c + f) {
			if (c < dist + f && f < dist + c)
				cout << 2 << '\n';
			else if (c == dist + f || f == dist + c)
				cout << 1 << '\n';
			else if(c > dist + f || f > dist + c)
				cout << 0 << '\n';
		}
	}

	return 0;
}