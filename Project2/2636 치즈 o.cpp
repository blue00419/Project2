#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[102][102] = { 0, };
int visit[102][102] = { 0, };
queue<pair<int, int>> q;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int precount = 0;
int x, y, mx, my;

int bfs(int cnt) {
	while (1) {
		q.push({ 1,1 });
		visit[1][1] = 1 + cnt;

		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				mx = x + dir[i][0];
				my = y + dir[i][1];

				if (mx > 0 && mx <= n && my > 0 && my <= m) {
					if (map[mx][my] == 0 &&
						(visit[mx][my] == cnt || visit[mx][my] == 0)) {
						q.push({ mx,my });
						visit[mx][my] = 1 + cnt;
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					x = i;
					y = j;

					for (int k = 0; k < 4; k++) {
						mx = x + dir[k][0];
						my = y + dir[k][1];
						if (mx > 0 && mx <= n && my > 0 && my <= m) {
							if (map[mx][my] == 0 && visit[mx][my] == 1 + cnt) {
								q.push({ x,y });
								visit[x][y] = 1 + cnt;
								break;
							}
						}
					}
				}
			}
		}

		int count = 0;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			map[x][y] = 0;
			count++;
		}
		if (count == 0) {
			return cnt;
		}
		precount = count;
		cnt++;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs(0) << endl;
	cout << precount << endl;
	return 0;
}