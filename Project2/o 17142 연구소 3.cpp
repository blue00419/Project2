#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef struct pi {
	int count;
	int x;
	int y;
	int birus;
};

#define MAX 50+1

int n, m;
int map[MAX][MAX];
vector<pair<int, int> > v;
bool visit[10];
int dir[4][2] = { {0,1},{0,-1}, {-1,0}, {1,0} };
int zerocount = 0;
static int minimum = 20000;

vector<int> bi;
int testmap[MAX][MAX];
bool testvisit[MAX][MAX];
queue<pi> q;

void dfs(int cnt, int start) {
	if (cnt == m) {
		bi.clear();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				testmap[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < 10; i++) {
			if (visit[i] == 1)
				bi.push_back(i);
		}
		memset(testvisit, 0, sizeof(testvisit));

		for (int i = 0; i < bi.size(); i++) {
			testmap[v[bi[i]].first][v[bi[i]].second] = 0;
			q.push({ 0, v[bi[i]].first ,v[bi[i]].second, 0 });
			testvisit[v[bi[i]].first][v[bi[i]].second] = 1;
		}

		int count, x, y, birus, mx, my, max = 0, changecount = 0;
		while (!q.empty()) {
			count = q.front().count;
			x = q.front().x;
			y = q.front().y;
			birus = q.front().birus;
			q.pop();

			if (count > max)
				max = count;

			for (int i = 0; i < 4; i++) {
				mx = x + dir[i][0];
				my = y + dir[i][1];

				if (mx > 0 && mx <= n && my > 0 && my <= n) {
					if (testvisit[mx][my] == 0 && testmap[mx][my] == 0) {
						if (birus) {
							testvisit[mx][my] = 1;
							testmap[mx][my] = count + 1 + birus;
							q.push({ count + 1 + birus, mx, my, 0 });
							changecount++;
						}
						else {
							testvisit[mx][my] = 1;
							testmap[mx][my] = count + 1;
							q.push({ count + 1, mx, my, 0 });
							changecount++;
						}
					}
					if (testvisit[mx][my] == 0 && testmap[mx][my] == -3) {
						testvisit[mx][my] = 1;
						testmap[mx][my] = count + 1;
						q.push({ count, mx, my, birus + 1 });
					}
				}
			}
		}

		if (changecount == zerocount) {
			if (minimum > max) {
				minimum = max;
			}
		}
		return;
	}

	for (int i = start; i < v.size(); i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(cnt + 1, i + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i,j });
				map[i][j] = -3;
			}
			else if (map[i][j] == 1) {
				map[i][j] = -2;
			}
			else if (map[i][j] == 0) {
				zerocount++;
			}
		}
	}
	dfs(0, 0);
	if (minimum == 20000) {
		cout << -1 << endl;
	}
	else {
		cout << minimum << endl;
	}
	return 0;
}