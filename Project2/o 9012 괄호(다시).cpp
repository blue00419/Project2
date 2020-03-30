#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	string str;
	int count;
	bool ok;
	for (int i = 0; i < t; i++) {
		cin >> str;
		count = 0;
		ok = false;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(')
				count++;
			else {
				if (count == 0) {
					ok = true;
					break;
				}
				else {
					count--;
				}
			}
		}

		if (ok)
			cout << "NO" << '\n';
		else if (count == 0) {
			cout << "YES" << '\n';
		}
		else
			cout << "NO" << '\n';
	}


	return 0;
}