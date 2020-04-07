#include<iostream>

using namespace std;

#define MAX 100

char map[MAX][MAX];

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
			}
		}

		int ly, ry, count, max=0;
		for (int i = 1; i < MAX - 1; i++) {
			for (int j = 1; j < MAX - 1; j++) {
				count = 1;
				ly = j;
				ry = j;
				while (1) {
					ly = ly - 1;
					ry = ry + 1;
					if (ly < 0 || ry >= MAX) {
						break;
					}
					if (map[i][ly] == map[i][ry]) {
						count += 2;
					}
					else {
						break;
					}
				}
				if (max < count)
					max = count;

				count = 0;
				ly = j + 1;
				ry = j;
				while (1) {
					ly = ly - 1;
					ry = ry + 1;
					if (ly < 0 || ry >= MAX) {
						break;
					}
					if (map[i][ly] == map[i][ry]) {
						count += 2;
					}
					else {
						break;
					}
				}
				if (max < count)
					max = count;
			}
		}

		int lx, rx;
		for (int i = 1; i < MAX - 1; i++) {
			for (int j = 1; j < MAX - 1; j++) {
				count = 1;
				lx = j;
				rx = j;
				while (1) {
					lx = lx - 1;
					rx = rx + 1;
					if (lx < 0 || rx >= MAX) {
						break;
					}
					if (map[lx][i] == map[rx][i]) {
						count += 2;
					}
					else {
						break;
					}
				}
				if (max < count)
					max = count;

				count = 0;
				lx = j + 1;
				rx = j;
				while (1) {
					lx = lx - 1;
					rx = rx + 1;
					if (lx < 0 || rx >= MAX) {
						break;
					}
					if (map[lx][i] == map[rx][i]) {
						count += 2;
					}
					else {
						break;
					}
				}
				if (max < count)
					max = count;
			}
		}
		cout << "#" << ii << " " << max << endl;
	}


	return 0;
}