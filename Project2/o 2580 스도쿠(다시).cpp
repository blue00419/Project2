#include<iostream>

using namespace std;

bool row[9][10], col[9][10], square[9][10];
int map[9][9];

void calc(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}
	
	int x = cnt / 9;
	int y = cnt % 9;
	if (map[x][y] != 0) {
		calc(cnt + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == 0 && col[y][i] == 0 &&
				square[(x / 3) * 3 + (y / 3)][i] == 0) {
				map[x][y] = i;
				row[x][i] = 1;
				col[y][i] = 1;
				square[(x / 3) * 3 + (y / 3)][i] = 1;
				calc(cnt + 1);
				square[(x / 3) * 3 + (y / 3)][i] = 0;
				col[y][i] = 0;
				row[x][i] = 0;
				map[x][y] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];

			row[i][map[i][j]] = 1;
			col[j][map[i][j]] = 1;
			square[(i / 3) * 3 + (j / 3)][map[i][j]] = 1;
		}
	}

	calc(0);
	return 0;
}