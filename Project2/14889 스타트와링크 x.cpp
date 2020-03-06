#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int map[21][21] = { 0, };
bool visit[21];
int start[10], link[10];
static int minimum = 1000000000;
int ssum, lsum;
int scount, lcount;
int sx, sy, lx, ly, temp;
static bool ok = false;

void dfs(int cur, int cnt) {
	if (cnt == n / 2) {
		scount = 0;
		lcount = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				link[lcount] = i;
				lcount++;
			}
			else {
				start[scount] = i;
				scount++;
			}
		}

		ssum = 0;
		lsum = 0;
		for (int i = 0; i < scount - 1; i++) {
			sx = start[i];
			lx = link[i];
			for (int j = i + 1; j < scount; j++) {
				sy = start[j];
				ly = link[j];
				if (sx > sy) {
					temp = sx;
					sx = sy;
					sy = temp;
				}
				if (lx > ly) {
					temp = lx;
					lx = ly;
					ly = temp;
				}
				ssum += map[sx][sy];
				lsum += map[lx][ly];
			}
		}
		minimum = min(minimum, abs(ssum - lsum));
		if (minimum == 0) {
			ok = true;
		}

		return;
	}

	for (int i = cur; i <= n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(cur ,cnt + 1);
			if (ok) {
				return;
			}
			visit[i] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (i > j) {
				map[j][i] += map[i][j];
			}
		}
	}
	dfs(1,0);

	cout << minimum << endl;

	return 0;
}