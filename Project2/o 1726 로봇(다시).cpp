#include<iostream>
#include<queue>

using namespace std;

typedef struct pi {
	int count;
	int direct;
	int x;
	int y;
};

#define MAX 100+1

int m, n;
int map[MAX][MAX];
int sp[3], ep[3];
bool visit[MAX][MAX][5];
queue<pi> q;
int dir[5][2] = { {0,0}, {3,4}, {3,4}, {1,2}, {1,2} };
int d[5][2] = { {0,0}, {0,1}, {0,-1}, {1,0}, {-1,0} };

void bfs() {
	q.push({ 0, sp[2], sp[0], sp[1]});
	visit[sp[0]][sp[1]][sp[2]] = 1;

	int count, direct, x, y, left, right, mx, my;
	while (!q.empty()) {
		count = q.front().count;
		direct = q.front().direct;
		x = q.front().x;
		y = q.front().y;
		q.pop();

		if (x == ep[0] && y == ep[1] && direct == ep[2]) {
			cout << count << '\n';
			return;
		}

		//¹æÇâ
		left = dir[direct][0];
		right = dir[direct][1];
		if (visit[x][y][left] == 0) {
			q.push({ count + 1, left, x, y });
			visit[x][y][left] = 1;
		}
		if (visit[x][y][right] == 0) {
			q.push({ count + 1, right, x, y });
			visit[x][y][right] = 1;
		}

		//go
		for (int i = 1; i <= 3; i++) {
			mx = x + d[direct][0] * i;
			my = y + d[direct][1] * i;
			if (mx > 0 && mx <= m && my > 0 && my <= n) {
				if (map[mx][my] == 1)
					break;
				if (map[mx][my] == 0 && visit[mx][my][direct] == 0) {
					q.push({ count + 1, direct, mx, my });
				}
			}
			else
				break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sp[0] >> sp[1] >> sp[2];
	cin >> ep[0] >> ep[1] >> ep[2];

	bfs();

	return 0;
}