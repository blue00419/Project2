#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n, m, k;
int map[500][500], cost[500][500];
int lx, rx, dy, uy;
bool visit[500][500];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int main() {
	int t;
	cin >> t;

	int mx, my;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n >> m >> k;

		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		lx = 200;
		rx = 200 + n;
		dy = 200 + m;
		uy = 200;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[200 + i][200 + j];
				cost[200 + i][200 + j] = map[200 + i][200 + j];
				if (map[200 + i][200 + j] != 0) {
					visit[200 + i][200 + j] = 1;
				}
			}
		}

		queue<pair<int, int> > q;
		for (int l = 0; l < k; l++) {
			for (int i = lx; i < rx; i++) {
				for (int j = uy; j < dy; j++) {
					if (cost[i][j] == 0 || visit[i][j] == 0) continue;

					if (map[i][j] == 0 && cost[i][j] != 0 && visit[i][j] == 1) {
						map[i][j]--;

						for (int jj = 0; jj < 4; jj++) {
							mx = i + dir[jj][0];
							my = j + dir[jj][1];
							if (visit[mx][my] == 0) {
								if (map[mx][my] < cost[i][j]) {
									map[mx][my] = cost[i][j];
									cost[mx][my] = cost[i][j];
									q.push({ mx,my });

								}
							}
						}
						continue;
					}
					if (map[i][j] != 0) {
						if (map[i][j] * (-1) != cost[i][j]) {
							map[i][j]--;
						}
					}
				}
			}

			while (!q.empty()) {
				mx = q.front().first;
				my = q.front().second;
				q.pop();
				visit[mx][my] = 1;
				if (mx < lx) lx--;
				if (mx == rx) rx++;
				if (my < uy) uy--;
				if (my == dy) dy++;
			}
		}

		int sum = 0;
		for (int i = lx; i < rx; i++) {
			for (int j = uy; j < dy; j++) {
				if (visit[i][j] == 1 && map[i][j]*(-1) != cost[i][j]) {
					sum++;
				}
			}
		}
		cout << sum << endl;
	}


	return 0;
}