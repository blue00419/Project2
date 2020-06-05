#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef struct pi {
	int x;
	int y;
	int count;
	int dir;
	bool move;
	int sum;
};

int n, m, k;
int map[100][100];
int dir[5][2] = { {0,0}, {-1,0}, {1,0}, {0,-1}, {0,1} };

int main() {
	int t;

	cin >> t;

	int a, b, c, d;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n >> m >> k;

		vector<pi> v;
		memset(map, -1, sizeof(map));

		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c >> d;
			v.push_back({ a, b, c, d, 0, c });
		}

		int x, y, mx, my;
		while (--m >= 0) {
			for (int i = 0; i < v.size(); i++) {
				v[i].move = 0;
				v[i].count = v[i].sum;
			}

			for (int i = 0; i < v.size(); i++) {
				if (v[i].count == 0) continue;

				x = v[i].x;
				y = v[i].y;
				if (map[x][y] == i) {
					map[x][y] = -1;
				}

				mx = x + dir[v[i].dir][0];
				my = y + dir[v[i].dir][1];

				if (mx == 0 || mx == n - 1 || my == 0 || my == n - 1) {

					v[i].x = mx;
					v[i].y = my;
					map[mx][my] = i;
					
					int z = v[i].dir;
					if (z == 1) {
						z = 2;
					}
					else if (z == 2) {
						z = 1;
					}
					else if (z == 3) {
						z = 4;
					}
					else if (z == 4) {
						z = 3;
					}
					v[i].dir = z;

					if (v[i].count % 2 == 1) {
						v[i].count--;
					}
					v[i].count /= 2;
					v[i].sum = v[i].count;
				}
				else {
					if (map[mx][my] != -1) {
						if (v[map[mx][my]].move == 1) {
							if (v[i].count > v[map[mx][my]].count) {
								v[i].sum += v[map[mx][my]].sum;
								v[map[mx][my]].count = 0;
								v[map[mx][my]].sum = 0;

								v[i].x = mx;
								v[i].y = my;
								map[mx][my] = i;
							}
							else {
								v[map[mx][my]].sum += v[i].sum;
								v[i].count = 0;
								v[i].sum = 0;
							}
						}
						else {
							v[i].x = mx;
							v[i].y = my;
							map[mx][my] = i;
						}
					}
					else {
						v[i].x = mx;
						v[i].y = my;
						map[mx][my] = i;
					}
				}
				v[i].move = 1;
			}
		}

		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i].sum;
		}

		cout << "#" << ii << " " << sum << endl;
	}

	return 0;
}