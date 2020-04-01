#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define MAX 50+1

struct pi {
	int f;
	int s;
};

int n, l, r;
int map[MAX][MAX];
bool visit[MAX][MAX];
queue<pi> q;
vector<pi> v;
int dir[4][2] = { {0,1},{0,-1}, {1,0}, {-1,0} };
int movecount = 0;

bool bfs() {
	memset(visit, 0, sizeof(visit));

	int x, y, mx, my, temp, size, sum;
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == 0) {
				v.clear();
				q.push({ i,j });
				visit[i][j] = 1;
				v.push_back({ i,j });


				while (!q.empty()) {
					x = q.front().f;
					y = q.front().s;
					q.pop();

					for (int i = 0; i < 4; i++) {
						mx = x + dir[i][0];
						my = y + dir[i][1];

						if (mx > 0 && mx <= n && my > 0 && my <= n) {
							if (visit[mx][my] == 0) {
								temp = abs(map[x][y] - map[mx][my]);
								if (l <= temp && r >= temp) {
									q.push({ mx, my });
									visit[mx][my] = 1;
									v.push_back({ mx,my });
								}
							}
						}
					}
				}

				if (v.size() > 1) {
					ok = true;
					
					size = v.size();
					sum = 0;
					for (int i = 0; i < size; i++) {
						sum += map[v[i].f][v[i].s];
					}
					sum = (int)(sum / v.size());
					for (int i = 0; i < size; i++) {
						map[v[i].f][v[i].s] = sum;
					}
				}
			}
		}
	}

	if (ok) {
		movecount++;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	bool ok;
	while (1) {
		ok = bfs();
		if (!ok)
			break;
	}

	cout << movecount << '\n';

	return 0;
}