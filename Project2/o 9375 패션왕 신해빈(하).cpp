#include<iostream>
#include<map>
#include<cstring>

using namespace std;

int maps[30];

int main() {
	int t;
	cin >> t;

	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;

		map<string, int> m;
		int index = 0;
		memset(maps, 0, sizeof(maps));

		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;

			if (!m.count(b)) {
				maps[index]++;
				m[b] = index;
				index++;
			}
			else {
				maps[m[b]]++;
			}
		}
		
		int result = 1;
		for (int i = 0; i < index; i++) {
			result *= (maps[i] + 1);
		}
		result--;
		cout << result << endl;
	}
}