#include<iostream>
#include<cstring>

using namespace std;

#define MAX 20+1

int map[MAX][MAX];
int n;
static int maximum = -1;
bool visit[MAX][MAX];

void dfs(int cnt) {
	if (cnt == 5) {
		return;
	}

	int remap[MAX][MAX];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			remap[i][j] = map[i][j];
		}
	}

	memset(visit, 0, sizeof(visit));
	int x, y;
	//up
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			x = i;
			while (1) {
				x--; 
				
				if (x == 1 || map[x][j] != 0) {
					if (map[x][j] == 0) {
						map[x][j] = map[i][j];
						map[i][j] = 0;
					}
					else if (map[x][j] == map[i][j] && visit[x][j] == 0) {
						map[x][j] += map[i][j];
						if (maximum < map[x][j])
							maximum = map[x][j];
						map[i][j] = 0;
						visit[x][j] = 1;
					}
					else if (x + 1 != i) {
						map[x + 1][j] = map[i][j];
						map[i][j] = 0;
					}
					break;
				}
				if (map[x][j] == 0)
					continue;
			}
		}
	}
	dfs(cnt + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = remap[i][j];
		}
	}

	memset(visit, 0, sizeof(visit));
	//right
	for (int i = n-1; i > 0; i--) {
		for (int j = 1; j <= n; j++) {
			y = i;
			while (1) {
				y++;

				if (y == n || map[j][y] != 0) {
					if (map[j][y] == 0) {
						map[j][y] = map[j][i];
						map[j][i] = 0;
					}
					else if (map[j][y] == map[j][i] && visit[j][y] == 0) {
						map[j][y] += map[j][i];
						if (maximum < map[j][y])
							maximum = map[j][y];
						map[j][i] = 0;
						visit[j][y] = 1;
					}
					else if (y - 1 != i) {
						map[j][y - 1] = map[j][i];
						map[j][i] = 0;
					}
					break;
				}
				if (map[j][y] == 0)
					continue;
			}
		}
	}
	dfs(cnt + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = remap[i][j];
		}
	}

	memset(visit, 0, sizeof(visit));
	//down
	for (int i = n-1; i > 0 ; i--) {
		for (int j = 1; j <= n; j++) {
			x = i;
			while (1) {
				x++;

				if (x == n || map[x][j] != 0) {
					if (map[x][j] == 0) {
						map[x][j] = map[i][j];
						map[i][j] = 0;
					}
					else if (map[x][j] == map[i][j] && visit[x][j] == 0) {
						map[x][j] += map[i][j];
						if (maximum < map[x][j])
							maximum = map[x][j];
						map[i][j] = 0;
						visit[x][j] = 1;
					}
					else if (x - 1 != i) {
						map[x - 1][j] = map[i][j];
						map[i][j] = 0;
					}
					break;
				}
				if (map[x][j] == 0)
					continue;
			}
		}
	}
	dfs(cnt + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = remap[i][j];
		}
	}

	memset(visit, 0, sizeof(visit));
	//left
	for (int i = 2; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			y = i;
			while (1) {
				y--;

				if (y == 1 || map[j][y] != 0) {
					if (map[j][y] == 0) {
						map[j][y] = map[j][i];
						map[j][i] = 0;
					}
					else if (map[j][y] == map[j][i] && visit[j][y] == 0) {
						map[j][y] += map[j][i];
						if (maximum < map[j][y])
							maximum = map[j][y];
						map[j][i] = 0;
						visit[j][y] = 1;
					}
					else if (y + 1 != i) {
						map[j][y + 1] = map[j][i];
						map[j][i] = 0;
					}
					break;
				}
				if (map[j][y] == 0)
					continue;
			}
		}
	}
	dfs(cnt + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = remap[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (maximum < map[i][j])
				maximum = map[i][j];
		}
	}

	dfs(0);

	cout << maximum << '\n';

	return 0;
}