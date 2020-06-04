#include<iostream>
#include<vector>

using namespace std;

typedef struct pi {
	int x;
	int y;
	int dir;
	int cost;
	bool die;
};

int dir[4][2] = { {1,0}, {-1,0}, {0,-1}, {0,1} };
vector<pi> v;
int map[4001][4001];

int calc() {
	int result = 0;
	vector<pi> re;

	while (1) {
		if (v.empty()) break;

		for (int i = 0; i < v.size(); i++) {
			map[v[i].x][v[i].y] = 0;
			v[i].x += dir[v[i].dir][0];
			v[i].y += dir[v[i].dir][1];

			if (v[i].x < 0 || v[i].x > 4000 || v[i].y < 0 || v[i].y > 4000) {
				v[i].die = 0;
				continue;
			}
			map[v[i].x][v[i].y] += v[i].cost;
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i].die == 0) continue;
			if (map[v[i].x][v[i].y] != v[i].cost) {
				result += map[v[i].x][v[i].y];
				map[v[i].x][v[i].y] = 0;
				v[i].die = 0;
			}
		}

		re.clear();
		re.assign(v.begin(), v.end());
		v.clear();
		for (int i = 0; i < re.size(); i++) {
			if (re[i].die == 1) {
				v.push_back(re[i]);
			}
		}
	}

	return result;
}

int main() {
	int t;

	cin >> t;

	int n;
	int a, b, c, d;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c >> d;
			a += 1000;
			b += 1000;
			a *= 2;
			b *= 2;
			v.push_back({ b,a,c,d,1 });
		}
		int result = calc();
		cout << "#" << ii << " " << result << endl;
	}

	return 0;
}