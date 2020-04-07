#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

#define MAX 16

int map[MAX][MAX];
bool visit[MAX][MAX];
int sp[2];
int dir[4][2] = { {0,1},{0,-1}, {1,0},{-1,0} };

bool bfs() {
	queue<pi> q;
	q.push({ sp[0], sp[1] });
	visit[sp[0]][sp[1]] = 1;

	int x, y, mx, my;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			mx = x + dir[i][0];
			my = y + dir[i][1];

			if (mx >= 0 && mx < MAX && my >= 0 && my < MAX) {
				if (map[mx][my] == 3) {
					return true;
				}
				if (map[mx][my] == 0 && visit[mx][my] == 0) {
					q.push({ mx, my });
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

	int t = 10;
	int n;
	char temp;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> temp;
				map[i][j] = temp - '0';
				if (map[i][j] == 2) {
					sp[0] = i;
					sp[1] = j;
				}
			}
		}

		memset(visit, 0, sizeof(visit));

		bool ok = bfs();

		cout << "#" << ii << " " << ok << endl;
	}

	return 0;
}