#include<iostream>
#include<cstring>

using namespace std;

#define MAX 100

char map[MAX];

void dfs(int cnt) {
	if (map[cnt] != '0') {
		dfs(cnt * 2);
		cout << map[cnt];
		dfs(cnt * 2 + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		memset(map, '0', sizeof(map));

		char temp;
		int num, a, b;
		for (int i = 0; i < n; i++) {
			cin >> num >> temp;
			if (num * 2 < n) {
				cin >> a >> b;
			}
			else if (num * 2 == n) {
				cin >> a;
			}
			map[num] = temp;
		}
		cout << "#" << ii << " ";
		dfs(1);
		cout << endl;
	}

	return 0;
}