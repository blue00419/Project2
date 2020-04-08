#include<iostream>
#include<cstring>

using namespace std;

#define MAX 100

char map[MAX][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;
	char temp;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		memset(map, '0', sizeof(map));

		for (int i = 0; i < n; i++) {
			cin >> map[i][0];
		}

		int x, y;
		bool ok;
		while (1) {
			ok = true;
			for (int i = 0; i < n - 1; i++) {
				x = i;
				y = i + 1;
				while (1) {
					if (map[y][1] == '1')
						y++;
					else
						break;
				}
				while (1) {
					if (x < 0 || y >= n)
						break;
					if (map[x][1] == '0' && map[y][1] == '0') {
						if (map[x][0] == map[y][0]) {
							map[x][1] = map[y][1] = '1';
							ok = false;
						}
						else
							break;
					}
					else
						break;
					x--;
					y++;
				}
			}
			if (ok)
				break;
		}

		cout << "#" << ii << " ";
		for (int i = 0; i < n; i++) {
			if (map[i][1] == '0')
				cout << map[i][0];
		}
		cout << endl;
	}


	return 0;
}