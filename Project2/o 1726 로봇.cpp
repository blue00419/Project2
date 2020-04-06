#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, pair<pair<int, int>,int > > pi;

#define MAX 100+1

int m, n;
int map[MAX][MAX];
int sp[3], ep[3];
bool visit[MAX][MAX][5];
queue<pi> q;
int d[5][2] = { {0,0}, {0,1}, {0,-1}, {1,0}, {-1,0} };

void bfs() {
	q.push({ 0,{{sp[0], sp[1]}, sp[2] } });
	visit[sp[0]][sp[1]][sp[2]] = 1;

	int count, x, y, dir, mx, my;
	while (!q.empty()) {
		count = q.front().first;
		x = q.front().second.first.first;
		y = q.front().second.first.second;
		dir = q.front().second.second;
		q.pop();

		if (x == ep[0] && y == ep[1] && dir == ep[2]) {
			cout << count << endl;
			return;
		}

		// 방향 전환
		if (dir == 1 || dir == 2) {
			if (visit[x][y][3] == 0) {
				visit[x][y][3] = 1;
				q.push({ count + 1,{{x,y}, 3} });
			}
			if (visit[x][y][4] == 0) {
				visit[x][y][4] = 1;
				q.push({ count + 1,{{x,y}, 4} });
			}
		}
		if (dir == 3 || dir == 4) {
			if (visit[x][y][1] == 0) {
				visit[x][y][1] = 1;
				q.push({ count + 1,{{x,y}, 1} });
			}
			if (visit[x][y][2] == 0) {
				visit[x][y][2] = 1;
				q.push({ count + 1,{{x,y}, 2} });
			}
		}

		// go~
		mx = x;
		my = y;
		for (int i = 0; i < 3; i++) {
			mx = mx + d[dir][0];
			my = my + d[dir][1];
			if (mx > 0 && mx <= m && my > 0 && my <= n
				&& visit[mx][my][dir] == 0) {
				if (map[mx][my] == 0) {
					visit[mx][my][dir] = 1;
					q.push({ count + 1,{{mx,my}, dir} });
				}
				else {
					break;
				}
			}
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