#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef pair<int, pair<int, int> > pi;

#define MAX 125

int n;
int map[MAX][MAX];
bool visit[MAX][MAX];
priority_queue<pi, vector<pi>, greater<pi> > q;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int count = 0;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		count++;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		q.push({ map[0][0], {0,0} });
		visit[0][0] = 1;

		int cost, x, y, mx, my;
		while (!q.empty()) {
			cost = q.top().first;
			x = q.top().second.first;
			y = q.top().second.second;
			q.pop();

			if ((x == n - 2 && y == n - 1) || (x == n -1 && y == n - 2)) {
				cout << "Problem " << count << ": " << cost + map[n-1][n-1] << '\n';
				break;
			}

			for (int i = 0; i < 4; i++) {
				mx = x + dir[i][0];
				my = y + dir[i][1];

				if (mx >= 0 && mx < n && my >= 0 && my < n) {
					if (visit[mx][my] == 0) {
						q.push({ cost + map[mx][my], {mx, my} });
						visit[mx][my] = 1;
					}
				}
			}
		}

		while (!q.empty())
			q.pop();
	}

	return 0;
}