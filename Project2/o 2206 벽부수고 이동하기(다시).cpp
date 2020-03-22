#include<iostream>
#include<queue>

using namespace std;

typedef pair<pair<int, int>, pair<int, int> > pi;

#define MAX 1000+1

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX][2];
queue<pi> q;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void bfs(int x, int y) {
	q.push({ {x,y}, {0,1} });
	visit[x][y][0] = 1;

	int b, w, mx, my;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		b = q.front().second.first;
		w = q.front().second.second;
		q.pop();

		if (x == n && y == m) {
			cout << w << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			mx = x + dir[i][0];
			my = y + dir[i][1];

			if (mx > 0 && mx <= n && my > 0 && my <= m) {
				if (b == 0) {
					if (map[mx][my] == 0) {
						if (visit[mx][my][0] == 0) {
							q.push({ {mx,my}, {b,w + 1} });
							visit[mx][my][0] = 1;
						}
					}
					else {
						if (visit[mx][my][1] == 0) {
							q.push({ {mx,my}, {1,w + 1} });
							visit[mx][my][1] = 1;
						}
					}
				}
				else {
					if (map[mx][my] == 0) {
						if (visit[mx][my][1] == 0) {
							q.push({ {mx,my}, {1,w + 1} });
							visit[mx][my][1] = 1;
						}
					}
				}
			}
		}
	}
	cout << -1 << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	char temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	bfs(1, 1);

	return 0;
}