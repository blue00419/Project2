#include<iostream>

using namespace std;

#define row 50
#define col 100

int map[row][col];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n, m;
		cin >> n >> m;

		char temp;
		int x=200, y=200;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> temp;
				map[i][j] = temp - '0';
				if (map[i][j] == 1 && x == 200 && y == 200) {
					x = i;
					y = j;
				}
			}
		}

		if (map[x][y + 1] == 0 && map[x][y + 2] == 0) {
			y -= 2; // 2
		}
		else if (map[x][y + 1] == 0 && map[x][y + 2] == 0
			&& map[x][y + 3] == 0) {
			y--; // 4
		}
		else if (map[x][y + 1] == 0 && map[x][y + 2] == 1
			&& map[x][y + 3] == 1) {
			if (map[x][y + 4] == 1) {
				y--; // 6
			}
			else {
				y -= 3; // 9
			}
		}
		else if (map[x][y + 1] == 1 && map[x][y + 2] == 0
			&& map[x][y + 3] == 1) {
			if (map[x][y + 4] == 1) {
				y--; // 8
			}
			else {
				y -= 3; // 0
			}
		}
		else if (map[x][y + 1] == 1 && map[x][y + 2] == 0
			&& map[x][y + 3] == 0) {
			if (map[x][y + 4] == 1) {
				y -= 2; // 1
			}
			else {
				y--; // 5
			}
		}
		else if (map[x][y + 1] == 1 && map[x][y + 2] == 1) {
			y--; // 7
		}
		else if (map[x][y + 1] == 1 && map[x][y + 2] == 1
			&& map[x][y + 3] == 1) {
			y--; // 3
		}

		int result[8] = { 0, };
		int count = 0;

		while (1) {
			if (map[x][y + 1] == 0) {
				if (map[x][y + 2] == 0) {
					// 0, 9
					if (map[x][y + 4] == 0) {
						result[count] = 9;
					}
					else {
						result[count] = 0;
					}
				}
				else {
					// 1,2
					if (map[x][y + 3] == 0) {
						result[count] = 2;
					}
					else {
						result[count] = 1;
					}
				}
			}
			else {
				if (map[x][y + 2] == 1) {
					if (map[x][y + 3] == 1) {
						// 3,7
						if (map[x][y + 4] == 0) {
							result[count] = 7;
						}
						else {
							result[count] = 3;
						}
					}
					else {
						//5, 8
						if (map[x][y + 4] == 0) {
							result[count] = 5;
						}
						else {
							result[count] = 8;
						}
					}
				}
				else {
					// 4,6
					if (map[x][y + 3] == 1) {
						result[count] = 6;
					}
					else {
						result[count] = 4;
					}
				}
			}

			count++;
			if (count == 8)
				break;
			y += 7;
		}

		int sum = 0;
		sum = result[0] + result[2] + result[4] + result[6];
		sum = sum * 3;
		sum += result[1] + result[3] + result[5] + result[7];
		if (sum % 10 == 0) {
			sum = 0;
			for (int i = 0; i < 8; i++) {
				sum += result[i];
			}

			cout << "#" << ii << " " << sum << endl;
		}
		else {
			cout << "#" << ii << " 0" << endl;
		}
	}

	return 0;
}