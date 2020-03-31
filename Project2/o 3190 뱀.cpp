#include<iostream>
#include<vector>

using namespace std;

#define MAX 100+2

int n, k, l;
int map[MAX][MAX];
vector<pair<int, char> > v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
				map[i][j] = 1;
		}
	}

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		map[a][b] = 2;
	}

	cin >> l;
	char temp;
	for (int i = 0; i < l; i++) {
		cin >> a >> temp;
		v.push_back({ a,temp });
	}

	int count = 0;
	int dir[4][2] = { { 0,1 }, {1,0}, {0,-1}, {-1,0} };
	vector<pair<int, int> > snake;
	snake.push_back({ 1,1 });
	map[1][1] = 3;

	int x, y, commcount = 0, d=0;
	while (1) {
		count++;
		x = snake.back().first + dir[d][0];
		y = snake.back().second + dir[d][1];
		if (map[x][y] == 2) {
			snake.push_back({ x,y });
			map[x][y] = 3;
		}
		else if (map[x][y] == 0) {
			map[snake[0].first][snake[0].second] = 0;
			map[x][y] = 3;
			snake.erase(snake.begin());
			snake.push_back({ x,y });
		}
		else if (map[x][y] == 1 || map[x][y] == 3) {
			break;
		}

		if (commcount < v.size()) {
			if (count == v[commcount].first) {
				if (v[commcount].second == 'D') {
					d++;
					if (d == 4)
						d = 0;
				}
				else {
					d--;
					if (d == -1)
						d = 3;
				}
				commcount++;
			}
		}
	}

	cout << count << '\n';

	return 0;
}