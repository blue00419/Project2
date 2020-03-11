#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define MAX 1000+1

string a, b;
int map[MAX][MAX] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	getline(cin, a);
	getline(cin, b);

	pair<pair<int, int>, int> m = { {0,0},0 };
	for (int i = 1; i <= b.length(); i++) {
		for (int j = 1; j <= a.length(); j++) {
			map[i][j] = max(max(map[i][j - 1], map[i - 1][j]),
				map[i - 1][j - 1] + (b[i - 1] == a[j - 1]));
			if (map[i][j] > m.second) {
				m.first.first = i;
				m.first.second = j;
				m.second = map[i][j];
			}
		}
	}
	char *str = new char[m.second + 1];
	str[m.second-1] = b[m.first.first - 1];

	int y = m.first.first - 1;
	int x = m.first.second - 1;
	int soo = m.second - 1;
	bool ok;
	for (int k = 0; k < m.second - 1; k++) {
		ok = false;
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= x; j++) {
				if (map[i][j] == soo) {
					str[soo-1] = b[i-1];
					y = i - 1;
					x = j - 1;
					soo--;
					ok = true;
				}
				if (ok)
					break;
			}
			if (ok)
				break;
		}
	}
	cout << m.second << endl;
	for (int i = 0; i < m.second; i++) {
		cout << str[i];
	}
	return 0;
}