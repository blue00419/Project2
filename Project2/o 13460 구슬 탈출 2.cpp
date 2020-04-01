#include<iostream>
#include<queue>

using namespace std;

typedef struct pi {
	int count;
	int rx;
	int ry;
	int bx;
	int by;
};

#define MAX 10

char map[MAX][MAX];
int n, m;
int rp[2], bp[2], ep[2]; // red, blue, end
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}  }; // À§ ¿À ¹Ø ¿Þ
queue<pi> q;

void bfs() {
	q.push({ 0, rp[0], rp[1], bp[0], bp[1] });

	int count, rx, ry, bx, by;
	int mrx, mry, mbx, mby;
	bool rok, bok;
	bool rend, bend;
	while (!q.empty()) {
		count = q.front().count;
		rx = q.front().rx;
		ry = q.front().ry;
		bx = q.front().bx;
		by = q.front().by;
		q.pop();

		if (count > 9) {
			cout << -1 << '\n';
			return;
		}

		// À§ ¿À ¹Ø ¿Þ
		for (int i = 0; i < 4; i++) {

			mrx = rx;
			mry = ry;
			mbx = bx;
			mby = by;
			rp[0] = rx;
			rp[1] = ry;
			bp[0] = bx;
			bp[1] = by;

			rend = false;
			bend = false;

			while (1) {
				rok = false;
				bok = false;
				if (!rend && !rok) {
					mrx = mrx + dir[i][0];
					mry = mry + dir[i][1];

					if (map[mrx][mry] == 'O') {
						rend = true;
						rp[0] = 0;
						rp[1] = 0;
					}
					else if (map[mrx][mry] == '.' && !(mrx == bp[0] && mry == bp[1])) {
						rp[0] = mrx;
						rp[1] = mry;
					}
					else if (map[mrx][mry] == '#' || (mrx == bp[0] && mry == bp[1])) {
						rok = true;

						mrx = mrx - dir[i][0];
						mry = mry - dir[i][1];
					}
				}

				if (!bend && !bok) {
					mbx = mbx + dir[i][0];
					mby = mby + dir[i][1];

					if (map[mbx][mby] == 'O') {
						bend = true;
						bp[0] = 0;
						bp[1] = 0;
					}
					else if (map[mbx][mby] == '.' && !(mbx == rp[0] && mby == rp[1])) {
						bp[0] = mbx;
						bp[1] = mby;
					}
					else if (map[mbx][mby] == '#' || (mbx == rp[0] && mby == rp[1])) {
						bok = true;

						mbx = mbx - dir[i][0];
						mby = mby - dir[i][1];
					}
				}

				if ((rok && bok) || (rok && bend) || (rend && bok) || (rend && bend))
					break;

			}

			if (rend && !bend) {
				cout << count + 1 << '\n';
				return;
			}
			if (!rend && !bend) {
				q.push({ count + 1, rp[0], rp[1], bp[0], bp[1] });
			}
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rp[0] = i;
				rp[1] = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				bp[0] = i;
				bp[1] = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'O') {
				ep[0] = i;
				ep[1] = j;
			}
		}
	}

	bfs();
	
	return 0;
}