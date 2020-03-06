#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int map[1001][1001] = { 0, };
char temp;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
bool visit[1001][1001][2] = { 0, };
queue<pair<int, pair<int, int>>> q;

void bfs(int x, int y, int b) {
	q.push({ b,{x,y} });
	visit[x][y][0] = 1;
	map[x][y] = 2;

	int mx, my;
	while (!q.empty()) {
		x = q.front().second.first;
		y = q.front().second.second;
		b = q.front().first;
		q.pop();

		if (x == n && y == m) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			mx = x + dir[i][0];
			my = y + dir[i][1];

			if (mx > 0 && mx <= n && my > 0 && my <= m) {
				if (b == 0) {
					if (map[mx][my] == -1 && visit[mx][my][1] == 0) { 
						map[mx][my] = map[x][y] + 1;
						visit[mx][my][1] = 1;
						q.push({ 1,{mx,my} });
					}
					else if (map[mx][my] != -1 && visit[mx][my][0] == 0){
						map[mx][my] = map[x][y] + 1;
						visit[mx][my][0] = 1;
						q.push({ b,{mx,my} });
					}
				}
				else {
					if (map[mx][my] != -1) {
						if (visit[mx][my][1] == 0) {
							map[mx][my] = map[x][y] + 1;
							visit[mx][my][1] = 1;
							q.push({ b,{mx,my} });
						}
						else {
							if (map[mx][my] > map[x][y] + 1) {
								map[mx][my] = map[x][y] + 1;
								q.push({ b,{mx,my} });
							}
						}
					}

				}
			}
		}
	}



	if (map[n][m] == 1000000) {
		cout << -1 << endl;
	}
	else {
		cout << map[n][m] - 1 << endl;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			if (temp == '1')
				map[i][j] = -1;
			else
				map[i][j] = 1000000;
		}
	}
	bfs(1, 1, 0);

	return 0;
}