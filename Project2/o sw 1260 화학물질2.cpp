#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 100
int map[MAX][MAX];
bool visit[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int length[20][2];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	queue<pair<int, int> > q;
	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> n;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		int lengthcount = 0;
		int xstart, xend, ystart, yend, x,y,mx,my;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0 && visit[i][j] == 0) {
					xstart = xend = i;
					ystart = yend = j;

					q.push({ i,j });
					while (!q.empty()) {
						x = q.front().first;
						y = q.front().second;
						q.pop();

						if (x > xend) {
							xend = x;
						}
						if (yend < y) {
							yend = y;
						}

						for (int k = 0; k < 4; k++) {
							mx = x + dir[k][0];
							my = y + dir[k][1];

							if (mx >= 0 && mx < n && my >= 0 && my < n) {
								if (map[mx][my] != 0 && visit[mx][my] == 0) {
									q.push({ mx,my });
									visit[mx][my] = 1;
								}
							}
						}
					}
					length[lengthcount][0] = xend - xstart + 1;
					length[lengthcount][1] = yend - ystart + 1;

					lengthcount++;
				}
			}
		}

		vector<pair<int, int> > v;

		v.push_back({ length[0][0], length[0][1] });

		for (int i = 1; i < lengthcount; i++) {
			for (int j = 1; j < lengthcount; j++) {
				if (length[j][0] == v[i - 1].second) {
					v.push_back({ length[j][0] , length[j][1] });
					break;
				}
				if (v[0].first == length[j][1]) {
					v.insert(v.begin(), { length[j][0], length[j][1] });
					break;
				}
			}
		}
		
		int d[MAX + 1];
		d[0] = v[0].first;
		for (int i = 0; i < v.size(); i++) {
			d[i + 1] = v[i].second;
		}

		int m[MAX][MAX];
		memset(m, 0x3f3f3f3f, sizeof(m));

		for (int dia = 0; dia < v.size(); dia++) {
			for (int i = 1; i <= v.size() - dia; i++) {
				int j = i + dia;
				if (j == i) {
					m[i][j] = 0;
					continue;
				}
				m[i][j] = 0x3f3f3f3f;
				for (int k = i; k <= j - 1; k++) {
					m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + (d[i - 1] * d[k] * d[j]));
				}
			}
		}

		cout << "#" << ii << " " << m[1][v.size()] << endl;
	}

	return 0;
}