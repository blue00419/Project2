#include<iostream>
#include<cstring>

using namespace std;

int n, x;
int map[20][20];
bool visit[20][20];

int main() {
	int t;

	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n >> x;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		int a, sum=0;
		bool ok;
		// 가로
		for (int i = 0; i < n; i++) {
			ok = true;
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					a = map[i][j];
					continue;
				}
				if (a == map[i][j]) continue;
				if (a - 1 > map[i][j]) {
					ok = false;
					break;
				}
				if (a + 1 < map[i][j]) {
					ok = false;
					break;
				}

				if (a + 1 == map[i][j]) {
					for (int k = 1; k < x; k++) {
						if (j - 1 - k < 0) {
							ok = false;
							break;
						}
						if (map[i][j - 1 - k] != a) {
							ok = false;
							break;
						}
						else {
							if (visit[i][j - 1 - k] == 1) {
								ok = false;
								break;
							}
						}
					}
					if (!ok) {
						break;
					}

					for (int k = 0; k < x; k++) {
						visit[i][j - 1 - k] = 1;
					}
					a = map[i][j];
				}
				else if (a - 1 == map[i][j]) {
					for (int k = 1; k < x; k++) {
						if (j + k == n) {
							ok = false;
							break;
						}
						if(map[i][j + k] != map[i][j]) {
							ok = false;
							break;
						}
						else {
							if (visit[i][j + k] == 1) {
								ok = false;
								break;
							}
						}
					}
					if (!ok) {
						break;
					}

					for (int k = 0; k < x; k++) {
						visit[i][j + k] = 1;
					}
					a = map[i][j];
				}
			}

			if (ok) {
				sum++;
			}
		}
		memset(visit, 0, sizeof(visit));

		// 세로
		for (int i = 0; i < n; i++) {
			ok = true;
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					a = map[j][i];
					continue;
				}
				if (a == map[j][i]) continue;
				if (a - 1 > map[j][i]) {
					ok = false;
					break;
				}
				if (a + 1 < map[j][i]) {
					ok = false;
					break;
				}

				if (a + 1 == map[j][i]) {
					for (int k = 1; k < x; k++) {
						if (j - 1 - k < 0) {
							ok = false;
							break;
						}
						if (map[j - 1 - k][i] != a) {
							ok = false;
							break;
						}
						else {
							if (visit[j - 1 - k][i] == 1) {
								ok = false;
								break;
							}
						}
					}
					if (!ok) {
						break;
					}

					for (int k = 0; k < x; k++) {
						visit[j - 1 - k][i] = 1;
					}
					a = map[j][i];
				}
				else if (a - 1 == map[j][i]) {
					for (int k = 1; k < x; k++) {
						if (j + k == n) {
							ok = false;
							break;
						}
						if (map[j + k][i] != map[j][i]) {
							ok = false;
							break;
						}
						else {
							if (visit[j + k][i] == 1) {
								ok = false;
								break;
							}
						}
					}
					if (!ok) {
						break;
					}

					for (int k = 0; k < x; k++) {
						visit[j + k][i] = 1;
					}
					a = map[j][i];
				}
			}

			if (ok) {
				sum++;
			}
		}
		memset(visit, 0, sizeof(visit));

		cout << "#" << ii << " " << sum << endl;
	}


	return 0;
}