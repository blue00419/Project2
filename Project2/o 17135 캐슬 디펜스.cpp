#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool map[16][15], remap[16][15];
int n, m, d;
int all=0;
bool visit[15];
int die = 0, pass = 0;
static int maxdie = 0;
int dir[3][2] = { {0,-1},{-1,0}, {0,1} };

void tern() {
	queue<pair<pair<int, int>, int> > q;
	vector<pair<int, int> > de;
	for (int i = 0; i < 15; i++) {
		if (visit[i] == 1) {
			q.push({ {n - 1, i}, 1 });
			int x, y, z;
			while (!q.empty()) {
				x = q.front().first.first;
				y = q.front().first.second;
				z = q.front().second;
				q.pop();

				if (map[x][y] == 1) {
					de.push_back({ x,y });
					break;
				}

				if (z + 1 <= d) {
					int mx, my;
					for (int j = 0; j < 3; j++) {
						mx = x + dir[j][0];
						my = y + dir[j][1];

						if (mx >= 0 && mx < n && my >= 0 && my < m) {
							q.push({ {mx, my}, z + 1 });
						}
					}
				}
			}
			while (!q.empty()) { q.pop(); }
		}
	}

	sort(de.begin(), de.end());
	de.erase(unique(de.begin(), de.end()), de.end());

	int size = de.size();
	for (int i = 0; i < size; i++) {
		map[de[i].first][de[i].second] = 0;
		die++;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				if (i == n - 1) {
					map[i][j] = 0;
					pass++;
				}
				else {
					map[i][j] = 0;
					map[i + 1][j] = 1;
				}
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == 3) {
		die = 0;
		pass = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				remap[i][j] = map[i][j];
			}
		}
		while (1) {
			tern();
			if (die + pass == all)
				break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = remap[i][j];
			}
		}
		if (die == all) {
			cout << die << endl;
			exit(0);
		}

		if (maxdie < die) {
			maxdie = die;
		}
		return;
	}

	for (int i = 0; i < m; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				all++;
			}
		}
	}

	dfs(0);
	cout << maxdie << endl;

	return 0;
}