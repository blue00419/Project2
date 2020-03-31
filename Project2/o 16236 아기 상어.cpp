#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, pair<int, int> > pi;

#define MAX 20+1

int n;
int map[MAX][MAX];
int sp[2], ss = 2, ec = 0; // 위치, 크기, 먹은개수
int dir[4][2] = { {-1,0} , {0,-1} , {0,1}, {1,0}  }; // 위 왼 오 아
int time = 0;
priority_queue<pi, vector<pi>, greater<pi> > q;
bool visit[MAX][MAX];

bool bfs() {
	while (!q.empty())
		q.pop();
	memset(visit, 0, sizeof(visit));
	q.push({ 0, { sp[0], sp[1]} });
	visit[sp[0]][sp[1]] = 1;

	int x, y, mx, my, count;
	while (!q.empty()) {
		count = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();
		if (map[x][y] < ss && map[x][y] != 0) {
			time += count;
			map[sp[0]][sp[1]] = 0;
			sp[0] = x;
			sp[1] = y;
			map[x][y] = 0;
			ec++;
			if (ec == ss) {
				ec = 0;
				ss++;
			}
			return true;
		}

		for (int i = 0; i < 4; i++) {
			mx = x + dir[i][0];
			my = y + dir[i][1];

			if (mx > 0 && mx <= n && my > 0 && my <= n) {
				if (visit[mx][my] == 0) {
					if (map[mx][my] <= ss) {
						q.push({ count + 1, {mx,my} });
					}
					visit[mx][my] = 1;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sp[0] = i;
				sp[1] = j;
			}
		}
	}

	bool ok;
	while (1) {
		ok = bfs();
		if (!ok)
			break;
	}
	cout << time << '\n';

	return 0;
}