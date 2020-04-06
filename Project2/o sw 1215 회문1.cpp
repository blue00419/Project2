#include<iostream>

using namespace std;

#define MAX 8

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
		int a, b, count =0;
		bool ok;
		if (n == 1) {
			count = 64;
		}
		else if (n == 2) {
			count = 0;
		}
		else {
			for (int i = 0; i < MAX; i++) {
				for (int j = 0; j < MAX - n + 1; j++) {
					a = j;
					b = j + n - 1;
					ok = true;
					while (1) {
						if (map[i][a] != map[i][b]) {
							ok = false;
							break;
						}
						a++;
						b--;
						if (a == b || a - 1 == b) {
							break;
						}
					}
					if (ok)
						count++;
				}
			}
			for (int i = 0; i < MAX; i++) {
				for (int j = 0; j < MAX - n + 1; j++) {
					a = j;
					b = j + n - 1;
					ok = true;
					while (1) {
						if (map[a][i] != map[b][i]) {
							ok = false;
							break;
						}
						a++;
						b--;
						if (a == b || a - 1 == b) {
							break;
						}
					}
					if (ok)
						count++;
				}
			}
		}
		cout << "#" << ii << " " << count << endl;
	}

	return 0;
}