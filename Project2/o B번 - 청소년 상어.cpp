#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct pi {
	int num=-1;
	int dir=0;
	int x=0;
	int y=0;
};

int dirs[9][2] = { {0,0}, {-1,0}, {-1,-1}, {0,-1}, {1,-1},
					{1,0}, {1,1}, {0,1}, {-1,1} };
static int result = 0;

bool compare(const pi& a, const pi& b) {
	if (a.num < b.num) {
		return true;
	}
	return false;
}

void dfs(int sum, int** map, vector<pi> v, pi shark) {

	if (sum > result) {
		result = sum;
	}


	pi temp;
	int num, x, y, dir, mx, my;
	for (int i = 0; i < v.size(); i++) {
		num = v[i].num;
		x = v[i].x;
		y = v[i].y;
		if (map[x][y] != num) continue;
		bool ok = false;
		bool turn;
		while (1) {
			dir = v[i].dir;
			mx = x + dirs[dir][0];
			my = y + dirs[dir][1];
			turn = false;

			if (mx < 0 || mx == 4 || my < 0 || my == 4) {
				turn = true;
			}
			else if (map[mx][my] == -1) {
				turn = true;
			}

			if (turn) {
				dir++;
				if (dir == 9) {
					dir = 1;
				}
				v[i].dir = dir;
			}
			else {
				if (map[mx][my] == 0) {
					map[x][y] = 0;
					map[mx][my] = num;
					v[i].x = mx;
					v[i].y = my;
				}
				else {
					temp = v[map[mx][my] - 1];
					v[map[mx][my] - 1].x = v[i].x;
					v[map[mx][my] - 1].y = v[i].y;
					v[i].x = temp.x;
					v[i].y = temp.y;

					int temps;
					temps = map[mx][my];
					map[mx][my] = map[x][y];
					map[x][y] = temps;
				}
				ok = true;
			}

			if (ok) break;

		}
	}


	int remap[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			remap[i][j] = map[i][j];
		}
	}

	mx = shark.x;
	my = shark.y;
	dir = shark.dir;
	temp = shark;
	int sum2;
	while (1) {
		mx += dirs[dir][0];
		my += dirs[dir][1];

		if (mx < 0 || mx == 4 || my < 0 || my == 4) {
			return;
		}
		if (map[mx][my] == 0) continue;

		num = map[mx][my];
		sum2 = sum + num;

		map[shark.x][shark.y] = 0;
		map[mx][my] = -1;
		shark = v[num - 1];
		shark.num = -1;

		dfs(sum2, map, v, shark);
		shark = temp;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				map[i][j] = remap[i][j];
			}
		}
	}
}

int main() {

	int** map = new int* [4];
	for (int i = 0; i < 4; i++) {
		map[i] = new int[4];
	}
	vector<pi> v;
	pi shark;
	
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			v.push_back({ a,b,i,j });
			map[i][j] = a;
		}
	}
	shark.dir = v[0].dir;
	map[0][0] = -1;
	int num = v[0].num;

	sort(v.begin(), v.end(), compare);

	dfs(num, map, v, shark);
	
	cout << result << endl;

	return 0;
}