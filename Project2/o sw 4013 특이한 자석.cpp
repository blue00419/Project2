#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
int map[4][8];

int main() {
	int t;

	cin >> t;

	int a, b, temp1, temp2;
	queue<pair<int, int> > q;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			a--;
			temp1 = a;
			temp2 = b;

			q.push({ a, b });

			// аб
			while (1) {
				if (temp1 - 1< 0) {
					break;
				}

				if (map[temp1][6] != map[temp1 - 1][2]) {
					temp2 *= -1;
					q.push({ temp1 - 1, temp2 });
				}
				else {
					break;
				}

				temp1--;
			}

			temp1 = a;
			temp2 = b;

			// ©Л
			while (1) {
				if (temp1 + 1 == 4) {
					break;
				}

				if (map[temp1][2] != map[temp1 + 1][6]) {
					temp2 *= -1;
					q.push({ temp1 + 1, temp2 });
				}
				else {
					break;
				}
				temp1++;
			}

			while (!q.empty()) {
				a = q.front().first;
				b = q.front().second;
				q.pop();

				if (b == 1) {
					temp1 = map[a][7];
					for (int i = 6; i >= 0; i--) {
						map[a][i + 1] = map[a][i];
					}
					map[a][0] = temp1;
				}
				else {
					temp1 = map[a][0];
					for (int i = 1; i < 8; i++) {
						map[a][i - 1] = map[a][i];
					}
					map[a][7] = temp1;
				}
			}
		}

		int sum = 0;
		if (map[0][0] == 1) {
			sum++;
		}
		if (map[1][0] == 1) {
			sum += 2;
		}
		if (map[2][0] == 1) {
			sum += 4;
		}
		if (map[3][0] == 1) {
			sum += 8;
		}

		cout << "#" << ii << " " << sum << endl;
	}


	return 0;
}