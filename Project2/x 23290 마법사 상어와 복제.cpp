#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fdir[9][2] = { {0,0}, {0, -1}, {-1, -1},{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1} };
int sdir[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };
int map[5][5] = { 0, };
bool visit[5][5];
static int moving;
static int killzone[3][2];

void dfs(int x, int y, int time, int count, vector<int> temp2[5][5], int kill[3][2]) {
	if (time == 3) {
		if (count > moving) {
			moving = count;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					killzone[i][j] = kill[i][j];
				}
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int mx = x + sdir[i][0];
		int my = y + sdir[i][1];
		if (mx > 0 && mx <= 4 && my > 0 && my <= 4) {
			if (visit[mx][my] == 0) {
				kill[time][0] = mx;
				kill[time][1] = my;
				visit[mx][my] = 1;
				dfs(mx, my, time + 1, count + temp2[mx][my].size(), temp2, kill);
				visit[mx][my] = 0;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v[5][5];
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b].push_back(c);
	}
	int s[2];
	cin >> s[0] >> s[1];

	for (int ii = 0; ii < m; ii++) {
		// 1 물고기 복사는 기존 v
		

		// 2 물고기 이동
		vector<int> temp2[5][5];
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				for (int k = 0; k < v[i][j].size(); k++) {
					int x = i;
					int y = j;
					int dir = v[i][j][k];
					int tdir = dir;
					bool ok = true;
					while (1) {
						int mx = x + fdir[tdir][0];
						int my = y + fdir[tdir][1];
						if (mx <= 4 && mx > 0 && my <= 4 && my > 0) {
							if (map[mx][my] == 0) {
								if (mx != s[0] || my != s[1]) {
									temp2[mx][my].push_back(tdir);
									ok = false;
									break;
								}
							}
						}
						tdir--;
						if (tdir == 0) tdir = 8;
						if (tdir == dir) break;
					}
					if (ok) {
						temp2[x][y].push_back(dir);
					}
				}
			}
		}

		// 3 상어 이동
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				visit[i][j] = 0;
			}
		}
		moving = -1;
		int kill[3][2] = { 0, };
		dfs(s[0], s[1], 0, 0, temp2, kill);

		for (int i = 0; i < 3; i++) {
			int x = killzone[i][0];
			int y = killzone[i][1];
			if (temp2[x][y].size() != 0) {
				temp2[x][y].clear();
				map[x][y] = 3;
			}
		}
		s[0] = killzone[2][0];
		s[1] = killzone[2][1];

		// 4 냄새 지우기
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				if (map[i][j] > 0) {
					map[i][j]--;
				}
			}
		}

		// 5 복제한거 가져오기
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				for (int k = 0; k < temp2[i][j].size(); k++) {
					v[i][j].push_back(temp2[i][j][k]);
				}
			}
		}
	}

	int result = 0;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			result += v[i][j].size();
		}
	}
	cout << result << endl;


	return 0;
}