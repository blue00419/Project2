#include<iostream>

using namespace std;

#define MAX 100

int map[MAX][MAX];
int dir[3][2] = { {-1,0}, {0,1}, {0,-1} };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	char n;
	
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		int x, y, d;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					x = i;
					y = j;
				}
			}
		}
		d = 0;
		bool ok;
		while (1) {
			x = x + dir[d][0];
			y = y + dir[d][1];
			ok = true;
			if (x == 0) {
				break;
			}
			if (d == 0) {
				if (y > 0) {
					if (map[x][y - 1] == 1) {
						d = 2;
						ok = false;
					}
				}
				if (ok) {
					if (y < 99) {
						if (map[x][y + 1] == 1) {
							d = 1;
						}
					}
				}
			}
			else {
				if (map[x - 1][y] == 1) {
					d = 0;
				}
			}
		}

		cout << "#" << n << " " << y << endl;
	}

	return 0;
}