#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;
	string str1, str2;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;
		cin >> str1 >> str2;

		int count = 0;
		bool ok;
		for (int i = 0; i < str2.size(); i++) {
			if (str2[i] == str1[0]) {
				ok = true;
				for (int j = 1; j < str1.size(); j++) {
					if (str2[i + j] != str1[j]) {
						ok = false;
						break;
					}
				}
				if (ok)
					count++;
			}
		}
		cout << "#" << n << " " << count << endl;
	}

	return 0;
}