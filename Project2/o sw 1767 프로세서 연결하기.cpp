#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int, int> pi;

#define MAX 12

int map[MAX][MAX];
int t,n;
vector<pi> v; // x,y
int dir[4][2] = { {0,1},{0,-1}, {1,0},{-1,0} };
int cost[MAX][2];
static int minimum[MAX][2];

void dfs(int cnt, int weight, int core) {
	if (cnt == v.size()) {
		if (minimum[cnt - 1][1] < cost[cnt - 1][1]) {
			minimum[cnt - 1][1] = cost[cnt - 1][1];
			minimum[cnt - 1][0] = cost[cnt - 1][0];
		}
		if (minimum[cnt - 1][1] == cost[cnt - 1][1]) {
			if (minimum[cnt - 1][0] > cost[cnt - 1][0]) {
				minimum[cnt - 1][0] = cost[cnt - 1][0];
			}
		}

		return;
	}

	int x, y;
	x = v[cnt].first;
	y = v[cnt].second;

	if (x == 0 || y == 0 || x == n - 1 || y == n - 1) {
		cost[cnt][0] = weight;
		cost[cnt][1] = core + 1;
		dfs(cnt + 1, weight, core + 1);
	}
	else {
		int mx, my;
		bool ok;
		bool one = true;

		int re[MAX][MAX];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				re[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int ii = 0; ii < n; ii++) {
				for (int jj = 0; jj < n; jj++) {
					map[ii][jj] = re[ii][jj];
				}
			}
			ok = true;
			mx = x;
			my = y;
			while (1) {
				mx = mx + dir[i][0];
				my = my + dir[i][1];
				if (mx >= 0 && mx < n && my >= 0 && my < n) {
					if (map[mx][my] == 1) {
						ok = false;
						break;
					}
				}
				else
					break;
			}
			if (ok) {
				int xmax, xmin, ymax, ymin;
				int result = 0;
				if (x == mx) {
					if (my == -1) {
						ymax = y;
						ymin = 0;
					}
					else if (my == n) {
						ymax = n - 1;
						ymin = y;
					}
					result = abs(y - my) - 1;

					for (int j = ymin; j <= ymax; j++) {
						map[x][j] = 1;
					}
				}
				else if (y == my) {
					if (mx == -1) {
						xmax = x;
						xmin = 0;
					}
					else if (mx == n) {
						xmax = n - 1;
						xmin = x;
					}
					result = abs(x - mx) - 1;
					for (int j = xmin; j <= xmax; j++) {
						map[j][y] = 1;
					}
				}
				one = false;
				cost[cnt][0] = weight + result;
				cost[cnt][1] = core + 1;
				dfs(cnt + 1, weight + result, core + 1);
			}
		}
		if (one) {

			if (minimum[cnt][1] < cost[cnt][1]) {
				minimum[cnt][1] = cost[cnt][1];
				minimum[cnt][0] = cost[cnt][0];
			}
			if (minimum[cnt][1] == cost[cnt][1]) {
				if (minimum[cnt][0] > cost[cnt][0]) {
					minimum[cnt][0] = cost[cnt][0];
				}
			}
			dfs(cnt + 1, weight, core);
		}
	}

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	for (int ii = 0; ii < t; ii++) {
		cin >> n;
		v.clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					if(i>0 && i<n-1 && j>0 && j<n-1)
						v.push_back({ i,j });
				}
			}
		}
		memset(cost, 0x3f3f3f3f, sizeof(cost));
		memset(minimum, 0, sizeof(minimum));

		dfs(0, 0, 0);

		for (int i = 11; i >= 0; i--) {
			if (minimum[i][1] != 0) {
				cout << "#" << ii+1 << " " << minimum[i][0] << endl;
				break;
			}
		}
	}


	return 0;
}