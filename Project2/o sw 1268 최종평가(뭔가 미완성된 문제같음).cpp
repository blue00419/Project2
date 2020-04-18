#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAX 1000+1

int map[MAX][MAX];
bool visit[MAX][MAX];
int r, n, k, a, b;
int two[10000+1], three[10000+1];

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	else if (b == 0)return a;
	else return gcd(b, a % b);
}

int calc(int x, int y) {
	memset(visit, 0, sizeof(visit));
	visit[x][y] = 1;

	int row, col, g, count= 0;
	bool xm, ym;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= r; j++) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				visit[i][j] = 1;
				count++;

				xm = ym = false;

				row = i-x;
				col = j-y;
				if (row < 0) {
					xm = true;
					row = abs(row);
				}
				if (col < 0) {
					ym = true;
					col = abs(col);
				}
				g = gcd(row, col);

				if (xm)
					row *= -1;
				if (ym)
					col *= -1;

				if (g != 1) {
					row = row / g;
					col = col / g;
				}

				int rowx = row+x, coly = col+ y;
				while (1) {
					if (map[rowx][coly] == 1 && visit[rowx][coly] == 0) {
						visit[rowx][coly] = 1;
					}
					rowx += row;
					coly += col;
					if (rowx < 1 || rowx > r || coly < 1 || coly > r)
						break;
				}
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	// gcd를 이용해서 가로 세로를 나눠주고 그 값만큼 증가하면서 다 visit처리
	for (int ii = 1; ii <= t; ii++) {
		memset(map, 0, sizeof(map));

		cin >> r >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			map[a][b] = 1;
		}

		int acount = 1, sum = 0;

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= r; j++) {
				if (map[i][j] == 1) {
					two[acount] = calc(i, j);
					sum += two[acount];
					acount++;
				}
			}
		}

		int other = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				two[j] = (((two[j] * k) + j) % n) + 1;

				two[n + j] = (((two[j] * j) + k) % n) + 1;
			}
			sort(two + 1, two + (2 * n) + 1);

			three[0] = 1;
			for (int j = 1; j <= (2 * n); j++) {
				three[j] = (((three[j - 1] * two[j]) + j) % n) + 1;
			}
			other += three[2 * n];
		}
		
		cout << "#" << ii << " " << sum << " " << other << endl;
	}


	return 0;
}