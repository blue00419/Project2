#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 8+1


typedef pair<int, pair<int, int> > pi;

bool compare(const pi& a, const pi& b) {
	if (a.first > b.first)
		return true;
	return false;
}

int n, m;
char map[MAX][MAX];
vector<pi> v;
static int counter = 64;

void right(int x, int y) {
	for (int i = y + 1; i <= m; i++) {
		if (map[x][i] == '0')
			map[x][i] = '#';
		if (map[x][i] == '6')
			break;
	}
}

void left(int x, int y) {
	for (int i = y - 1; i > 0; i--) {
		if (map[x][i] == '0')
			map[x][i] = '#';
		if (map[x][i] == '6')
			break;
	}
}

void down(int x, int y) {
	for (int i = x + 1; i <= n; i++) {
		if (map[i][y] == '0')
			map[i][y] = '#';
		if (map[i][y] == '6')
			break;
	}
}

void up(int x, int y) {
	for (int i = x - 1; i > 0; i--) {
		if (map[i][y] == '0')
			map[i][y] = '#';
		if (map[i][y] == '6')
			break;
	}
}

void dfs(int cnt) {
	if (cnt == v.size()) {
		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '0')
					count++;
			}
		}
		if (counter > count)
			counter = count;
		return;
	}

	char remap[MAX][MAX];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			remap[i][j] = map[i][j];
		}
	}

	int x, y;

	if (v[cnt].first == 5) {
		x = v[cnt].second.first;
		y = v[cnt].second.second;
		right(x, y);
		left(x, y);
		down(x, y);
		up(x, y);
		dfs(cnt + 1);
	}
	else if (v[cnt].first == 4) {
		x = v[cnt].second.first;
		y = v[cnt].second.second;

		// 1À§ 2¿À 3¹Ø 4¿Þ
		int dir[4][3] = { {1,2,3}, {2,3,4}, {3,4,1}, {4,1,2} };
		int a, b, c;
		for (int i = 0; i < 4; i++) {
			a = dir[i][0];
			b = dir[i][1];
			c = dir[i][2];
			if (a == 1 || b == 1 || c == 1) {
				if( x-1 > 0 && map[x - 1][y] != '6')
					up(x, y);
			}
			if (a == 2 || b == 2 || c == 2) {
				if (y + 1 <= m && map[x][y + 1] != '6')
					right(x, y);
			}
			if (a == 3 || b == 3 || c == 3) {
				if (x + 1 <= n && map[x + 1][y] != '6')
					down(x, y);
			}
			if (a == 4 || b == 4 || c == 4) {
				if (y - 1 > 0 && map[x][y - 1] != '6')
					left(x, y);
			}
			dfs(cnt + 1);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					map[i][j] = remap[i][j];
				}
			}
		}
	}
	else if (v[cnt].first == 3) {
		x = v[cnt].second.first;
		y = v[cnt].second.second;

		// 1À§ 2¿À 3¹Ø 4¿Þ
		int dir[4][2] = { {1,2}, {2,3}, {3,4}, {4,1} };
		int a, b;
		for (int i = 0; i < 4; i++) {
			a = dir[i][0];
			b = dir[i][1];
			if (a == 1 || b == 1) {
				if (x - 1 > 0 && map[x - 1][y] != '6')
					up(x, y);
			}
			if (a == 2 || b == 2) {
				if (y + 1 <= m && map[x][y + 1] != '6')
					right(x, y);
			}
			if (a == 3 || b == 3) {
				if (x + 1 <= n && map[x + 1][y] != '6')
					down(x, y);
			}
			if (a == 4 || b == 4) {
				if (y - 1 > 0 && map[x][y - 1] != '6')
					left(x, y);
			}
			dfs(cnt + 1);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					map[i][j] = remap[i][j];
				}
			}
		}
	}
	else if (v[cnt].first == 2) {
		x = v[cnt].second.first;
		y = v[cnt].second.second;

		// 1À§ 2¿À 3¹Ø 4¿Þ
		int dir[2][2] = { {1,3}, {2,4} };
		int a, b;
		for (int i = 0; i < 2; i++) {
			a = dir[i][0];
			b = dir[i][1];
			if (a == 1 || b == 1) {
				if (x - 1 > 0 && map[x - 1][y] != '6')
					up(x, y);
			}
			if (a == 2 || b == 2) {
				if (y + 1 <= m && map[x][y + 1] != '6')
					right(x, y);
			}
			if (a == 3 || b == 3) {
				if (x + 1 <= n && map[x + 1][y] != '6')
					down(x, y);
			}
			if (a == 4 || b == 4) {
				if (y - 1 > 0 && map[x][y - 1] != '6')
					left(x, y);
			}
			dfs(cnt + 1);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					map[i][j] = remap[i][j];
				}
			}
		}
	}
	else if (v[cnt].first == 1) {
		x = v[cnt].second.first;
		y = v[cnt].second.second;

		// 1À§ 2¿À 3¹Ø 4¿Þ
		int dir[4] = { 1,2,3,4 };
		int a;
		for (int i = 0; i < 4; i++) {
			a = dir[i];
			if (a == 1) {
				if (x - 1 > 0 && map[x - 1][y] != '6')
					up(x, y);
			}
			if (a == 2) {
				if (y + 1 <= m && map[x][y + 1] != '6')
					right(x, y);
			}
			if (a == 3) {
				if (x + 1 <= n && map[x + 1][y] != '6')
					down(x, y);
			}
			if (a == 4) {
				if (y - 1 > 0 && map[x][y - 1] != '6')
					left(x, y);
			}
			dfs(cnt + 1);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					map[i][j] = remap[i][j];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] != '0' && map[i][j] != '6')
				v.push_back({ map[i][j] - '0', {i,j} });
		}
	}

	sort(v.begin(), v.end(), compare);

	dfs(0);

	cout << counter << '\n';
	return 0;
}