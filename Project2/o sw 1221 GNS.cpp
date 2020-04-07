#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int map[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	string num, str;
	int n;
	for (int ii = 1; ii <= t; ii++) {
		cin >> num;
		cin >> n;
		memset(map, 0, sizeof(map));

		for (int i = 0; i < n; i++) {
			cin >> str;
			if (str == "ZRO") {
				map[0]++;
			}
			else if (str == "ONE") {
				map[1]++;
			}
			else if (str == "TWO") {
				map[2]++;
			}
			else if (str == "THR") {
				map[3]++;
			}
			else if (str == "FOR") {
				map[4]++;
			}
			else if (str == "FIV") {
				map[5]++;
			}
			else if (str == "SIX") {
				map[6]++;
			}
			else if (str == "SVN") {
				map[7]++;
			}
			else if (str == "EGT") {
				map[8]++;
			}
			else if (str == "NIN") {
				map[9]++;
			}
		}

		cout << num << endl;
		for (int i = 0; i < map[0]; i++) {
			cout << "ZRO ";
		}
		for (int i = 0; i < map[1]; i++) {
			cout << "ONE ";
		}
		for (int i = 0; i < map[2]; i++) {
			cout << "TWO ";
		}
		for (int i = 0; i < map[3]; i++) {
			cout << "THR ";
		}
		for (int i = 0; i < map[4]; i++) {
			cout << "FOR ";
		}
		for (int i = 0; i < map[5]; i++) {
			cout << "FIV ";
		}
		for (int i = 0; i < map[6]; i++) {
			cout << "SIX ";
		}
		for (int i = 0; i < map[7]; i++) {
			cout << "SVN ";
		}
		for (int i = 0; i < map[8]; i++) {
			cout << "EGT ";
		}
		for (int i = 0; i < map[9]; i++) {
			cout << "NIN ";
		}
		cout << endl;
	}

	return 0;
}