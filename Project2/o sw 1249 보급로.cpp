#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

#define MAX 100

typedef pair<int, pair<int, int> > pi;

int map[MAX][MAX];
int visit[MAX][MAX];

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int bfs(int n) {
	priority_queue<pi, vector<pi>, greater<pi> > q;
	q.push({ 0,{0,0} });
	visit[0][0] = 0;
	
	int time, x, y, mx, my;
	while (!q.empty()) {
		time = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();

		if (x == n && y == n) {
			return time;
		}
		for (int i = 0; i < 4; i++) {
			mx = x + dir[i][0];
			my = y + dir[i][1];

			if (mx >= 0 && mx <= n && my >= 0 && my <= n) {
				if (visit[mx][my] > time + map[mx][my]) {
					visit[mx][my] = time + map[mx][my];
					q.push({ time + map[mx][my], { mx, my} });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> n;
		memset(visit, 0x3f3f3f3f, sizeof(visit));

		char a;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				map[i][j] = a - '0';
			}
		}
		n--;

		cout << "#" << ii << " " << bfs(n) << endl;
	}

	return 0;
}