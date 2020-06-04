#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

int n, w, h;
int map[15][12], remap[15][12];
static int minimum;
vector<int> v;
bool visit[15][12];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

void calc(int a) {
	int b = 0;
	memset(visit, 0, sizeof(visit));
	queue<pair<int, pair<int, int> > > q;
	while (1) {
		if (map[b][a] != 0) {
			q.push({ map[b][a] - 1, {b, a} });
			map[b][a] = 0;
			visit[b][a] = 1;
			break;
		}
		b++;
		if (b == h)
			return;
	}

	int cost, x, y, mx, my;
	while (!q.empty()) {
		cost = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			mx = x;
			my = y;
			for (int j = 0; j < cost; j++) {
				mx += dir[i][0];
				my += dir[i][1];

				if (mx >= 0 && mx < h && my >= 0 && my < w) {
					if (visit[mx][my] == 0 && map[mx][my] != 0) {
						q.push({ map[mx][my] - 1, {mx,my} });
						map[mx][my] = 0;
						visit[mx][my] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = h - 2; j >= 0; j--) {
			if (map[j][i] != 0) {
				mx = j;

				while (1) {
					mx++;
					if (map[mx][i] != 0 || mx == h) {
						mx--;
						if (j != mx) {
							map[mx][i] = map[j][i];
							map[j][i] = 0;
						}
						break;
					}
				}
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < v.size(); i++) {
			calc(v[i]);
		}

		int sum = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] != 0) {
					sum++;
				}
				map[i][j] = remap[i][j];
			}
		}
		if (minimum > sum) {
			minimum = sum;
		}
		return;
	}
	for (int i = 0; i < w; i++) {
		v.push_back(i);
		dfs(cnt + 1);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;

	int temp;
	for (int ii = 1; ii <= t; ii++) {

		cin >> n >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				remap[i][j] = map[i][j];
			}
		}
		v.clear();
		minimum = 0x3f3f3f3f;
		dfs(0);
		cout << "#" << ii << " " << minimum << endl;
	}
}