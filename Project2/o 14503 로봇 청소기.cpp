#include<iostream>

using namespace std;

#define MAX 50

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int r[3];
int dir[4][2] = { {0,-1},{1,0}, {0,1}, {-1,0} };
int back[4][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> r[0] >> r[1] >> r[2];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int count = 0, mx, my, x, y, d;
	while (1) {
		x = r[0];
		y = r[1];
		if (map[x][y] == 0 && visit[x][y] == 0) {
			visit[x][y] = 1;
			count++;
		}
		
		bool ok = false;
		for (int i = 0; i < 4; i++) {
			d = i - r[2];
			if (d < 0)
				d += 4;

			mx = x + dir[d][0];
			my = y + dir[d][1];

			if (mx > 0 && mx < n - 1 && my > 0 && my < m - 1) {
				if (map[mx][my] == 0 && visit[mx][my] == 0) {
					r[0] = mx;
					r[1] = my;
					if (x - mx > 0)
						r[2] = 0;
					else if (mx - x > 0)
						r[2] = 2;
					else if (y - my > 0)
						r[2] = 3;
					else if (my - y > 0)
						r[2] = 1;
					ok = true;
					break;
				}
			}
		}

		if (ok)
			continue;

		ok = false;
		for (int i = 0; i < 4; i++) {
			if (i == r[2]) {
				x += back[i][0];
				y += back[i][1];
				if (map[x][y] == 0) {
					ok = true;
					r[0] = x;
					r[1] = y;
					break;
				}
			}
		}

		if (ok)
			continue;

		break;
	}
	cout << count << endl;
	return 0;
}