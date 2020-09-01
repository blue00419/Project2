#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int r, c;
bool map[100][100];
bool visit[100][100];
int dir[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };

bool check(int x, int y, int** remap) {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;
	remap[x][y] = 2;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0];
			int my = y + dir[i][1];

			if (mx >= 0 && mx < r && my >= 0 && my < c) {
				if (visit[mx][my] == 0 && map[mx][my] == 1) {
					if (mx == r-1) return 1;
					visit[mx][my] = 1;
					remap[mx][my] = 2;
					q.push({ mx,my });
				}
			}
		}
	}

	return 0;
}

void move(int row, int col) {
	int** remap = new int* [r];
	for (int i = 0; i < r; i++) {
		remap[i] = new int[c];
		for (int j = 0; j < c; j++) {
			remap[i][j] = map[i][j];
		}
	}

	if (!check(row, col, remap)) {

		bool end = false;
		while (1) {

			for (int i = r - 1; i >= 0; i--) {
				for (int j = c - 1; j >= 0; j--) {
					if (remap[i][j] == 2) {
						if (i + 1 != r) {
							if (remap[i + 1][j] == 0) {
								remap[i + 1][j] = 2;
								remap[i][j] = 0;
							}
							else {
								end = true;
							}
						}
						else {
							end = true;
						}
					}
					if (end)
						break;
				}
				if (end)
					break;
			}

			if (end)
				break;

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (remap[i][j] == 0) {
						map[i][j] = 0;
					}
					else {
						map[i][j] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < r; i++) {
		delete remap[i];
	}
	delete[] remap;
}

int main() {
	cin >> r >> c;


	char temp;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> temp;
			if (temp == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}

	int n;
	cin >> n;

	int row, col;
	for (int ii = 0; ii < n; ii++) {
		cin >> row;
		row = r - row;
		col = -1;
		if (ii % 2 == 0) {
			for (int i = 0; i < c; i++) {
				if (map[row][i] == 1) {
					col = i;
					break;
				}
			}
		}
		else {
			for (int i = c - 1; i >= 0; i--) {
				if (map[row][i] == 1) {
					col = i;
					break;
				}
			}
		}

		if (col == -1) continue;
		map[row][col] = 0;

		// ¿Þ
		if (col - 1 >= 0) {
			if (map[row][col - 1] == 1) {
				move(row, col - 1);
			}
		}

		// ¿À
		if (col + 1 < c) {
			if (map[row][col + 1] == 1) {
				move(row, col + 1);
			}
		}

		// À§
		if (row - 1 >= 0) {
			if (map[row - 1][col] == 1) {
				move(row - 1, col);
			}
		}

		// ¾Æ·¡
		if (row + 1 < r) {
			if (map[row + 1][col] == 1) {
				move(row + 1, col);
			}
		}

	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 1) {
				cout << 'x';
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}
	
	return 0;
}