#include<iostream>
#include<vector>

using namespace std;

typedef pair<pair<int, int>, int> pi;

#define MAX 12+1

int map[MAX][MAX];
int n, k;
vector<pi> v;
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int h[MAX][MAX][10];

vector<int> blue(int x, int y, int d) {
	if (d == 1)
		d = 2;
	else if (d == 2)
		d = 1;
	else if (d == 3)
		d = 4;
	else if (d == 4)
		d = 3;

	x = x + (2 * dir[d][0]);
	y = y + (2 * dir[d][1]);

	vector<int> result;
	result.push_back(x);
	result.push_back(y);
	result.push_back(d);

	return result;
}

void calc(int cnt) {
	if (cnt == 1000) {
		cout << -1 << endl;
		exit(0);
	}
	int size,x,y, mx, my, d, p;

	size = v.size();

	int scount = 0;
	int s[10];
	for (int i = 1; i < size; i++) {
		x = v[i].first.first;
		y = v[i].first.second;
		p = h[x][y][0];
		if (p == i) {
			s[scount] = i;
			scount++;
		}
	}

	for (int i = 0; i < scount; i++) {
		x = v[s[i]].first.first;
		y = v[s[i]].first.second;
		p = h[x][y][0];

		d = v[p].second;
		mx = x + dir[d][0];
		my = y + dir[d][1];

		if (mx < 1 || mx >n || my<1 || my>n) {
			vector<int> result = blue(mx, my, d);
			mx = result[0];
			my = result[1];
			d = result[2];
			v[p].second = d;
			if (map[mx][my] == 2) {
				continue;
			}
		}
		else if (mx > 0 && mx <= n && my > 0 && my <= n) {
			if (map[mx][my] == 2) {
				vector<int> result = blue(mx, my, d);
				mx = result[0];
				my = result[1];
				d = result[2];
				v[p].second = d;
				if (mx < 1 || mx >n || my<1 || my>n) {
					continue;
				}
				if (map[mx][my] == 2) {
					continue;
				}
			}
		}

		if (map[mx][my] == 1) {
			int change[10];
			int ksize = 0;
			for (int k = 0; k < 10; k++) {
				if (h[x][y][k] != 0) {
					change[k] = h[x][y][k];
					ksize++;
				}
				else {
					break;
				}
			}
			for (int k = 0; k < ksize; k++) {
				h[x][y][k] = change[ksize - 1 - k];
			}
		}

		int count = 0;
		bool end = false;
		while (1) {
			if (end)
				break;
			if (h[mx][my][count] == 0) {
				for (int k = 0; k < 10; k++) {
					
					if (count + k >= 4) {
						cout << cnt + 1 << endl;
						exit(0);
					}
					if (h[x][y][k] != 0) {
						h[mx][my][count + k] = h[x][y][k];
						v[h[x][y][k]].first.first = mx;
						v[h[x][y][k]].first.second = my;
						h[x][y][k] = 0;
					}
					else {
						end = true;
						break;
					}
				}
			}
			else
				count++;
		}
		
	}

	calc(cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) { // 0 white, 1 red, 2 blue
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	v.push_back({ {0,0},0 });
	int a, b, c;
	for (int i = 1; i <= k; i++) {
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
		h[a][b][0] = i;
	}

	calc(0);

	return 0;
}