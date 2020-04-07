#include<iostream>
#include<cstring>

using namespace std;

#define MAX 100

int map[MAX][MAX];
bool visit[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> map[i][j];
				visit[i][j] = 0;
			}
		}

		int end;
		for (int i = 0; i < MAX; i++) {
			end = 100;
			for (int j = 99; j >= 0; j--) {
				if (map[j][i] == 2) {
					end = j;
				}
				else if (map[j][i] == 1) {
					if (end == 100)
						map[j][i] = 0;
					else {
						map[j][i] = 0;
						map[end - 1][i] = 1;
						end--;
					}
				}
			}
		}

		for (int i = 0; i < MAX; i++) {
			end = -1;
			for (int j = 0; j <MAX; j++) {
				if (map[j][i] == 1) {
					end = j;
				}
				else if (map[j][i] == 2) {
					if (end == -1)
						map[j][i] = 0;
					else {
						map[j][i] = 0;
						map[end + 1][i] = 2;
						end++;
					}
				}
			}
		}

		int count = 0, cnt;
		int x, y;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0) {
					x = i;
					y = j;
					visit[x][y] = 1;
					cnt = 0;
					while (1) {
						x++;
						if (x >= MAX) {
							break;
						}
						if (cnt == 0) {
							if (map[x][y] == 2) {
								count++;
								cnt++;
							}
						}
						else if (cnt == 1) {
							if (map[x][y] != 2) {
								break;
							}
						}
						visit[x][y] = 1;
					}
				}
			}
		}
		cout << "#" << ii << " " << count << endl;
	}
	return 0;
}