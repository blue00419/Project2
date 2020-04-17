#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, pair<int, int> > pi;

#define MAX 100

int map[MAX][MAX];
bool visit[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{ 1,0},{-1,0} };

bool compare(const pi& a, const pi& b) {
	if (a.first < b.first)
		return true;
	if (a.first == b.first) {
		if (a.second.first < b.second.first)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				visit[i][j] = 0;
			}
		}

		vector<pi> v;
		queue<pair<int, int> > q;
		int xstart, xend, ystart, yend,x,y, mx, my;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0 && visit[i][j] == 0) {
					xstart = xend = i;
					ystart = yend = j;
					visit[i][j] = 1;

					q.push({ i,j });
					while (!q.empty()) {
						x = q.front().first;
						y = q.front().second;
						q.pop();

						if (x > xend)
							xend = x;
						if (y > yend)
							yend = y;

						for (int i = 0; i < 4; i++) {
							mx = x + dir[i][0];
							my = y + dir[i][1];

							if (mx >= 0 && mx < n && my >= 0 && my < n) {
								if (map[mx][my] != 0 && visit[mx][my] == 0) {
									q.push({ mx,my });
									visit[mx][my] = 1;
								}
							}
						}
					}
					xend = xend - xstart + 1;
					yend = yend - ystart + 1;

					v.push_back({ xend * yend, {xend, yend} });
				}
			}
		}

		sort(v.begin(), v.end(), compare);

		cout << "#" << ii << " " << v.size();
		for (int i = 0; i < v.size(); i++) {
			cout << " " << v[i].second.first << " " << v[i].second.second;
		}
		cout << endl;
	}

	return 0;
}