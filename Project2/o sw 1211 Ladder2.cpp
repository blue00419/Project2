#include<iostream>

using namespace std;

#define MAX 100

int map[MAX][MAX];
int dir[3][2] = { {1,0}, {0,1}, {0,-1} };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> map[i][j];
			}
		}

		int x, y, d;
		int max[2] = { 0, }, count;
		bool ok;
		for (int i = 0; i < MAX; i++) {
			if (map[0][i] == 1) {
				x = 0;
				y = i;
				d = 0;
				count = 0;
				while (1) {
					count++;
					x = x + dir[d][0];
					y = y + dir[d][1];
					ok = true;

					if (x == MAX-1) {
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
							if (y < MAX - 1) {
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
				if (max[0] >= count || max[0] == 0) {
					max[0] = count;
					max[1] = i;
				}
			}
		}

		cout << "#" << n << " " << max[1] << endl;
	}

	return 0;
}