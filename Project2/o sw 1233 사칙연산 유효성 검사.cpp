#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		string temp;
		int num, a, b;
		bool ok = true;
		bool end = false;
		for (int i = 0; i < n; i++) {
			cin >> num >> temp;
			ok = true;
			if (num * 2 < n) {
				cin >> a >> b;
				ok = false;
			}
			else if (num * 2 == n) {
				cin >> a;
			}

			if (ok) {
				if (temp == "+" || temp == "-"
					|| temp == "*" || temp == "/") {
					end = true;
				}
			}
			else {
				if (temp != "+" && temp != "-"
					&& temp != "*" && temp != "/") {
					end = true;
				}
			}
		}
		if (end) {
			cout << "#" << ii << " 0" << endl;
		}
		else {
			cout << "#" << ii << " 1" << endl;
		}
	}

	return 0;
}