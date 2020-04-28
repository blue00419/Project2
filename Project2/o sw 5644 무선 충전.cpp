#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

#define MAX 10+1

vector<pair<int, int> > map[MAX][MAX];
vector<int> amove, bmove;
static bool visit[MAX][MAX];
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int userdir[5][2] = { {0,0}, {-1,0}, {0,1}, {1,0}, {0,-1} };

// À§ ¹Ø ¿Þ ¿À
void dfs(int cnt, int aa, int ab, int ac, int ad, int key) {
	if (aa < 1 || aa > 10 || ab < 1 || ab > 10) return;
	if (cnt != 0 && cnt <= ac) {
		if (visit[aa][ab] == 0) {
			visit[aa][ab] = 1;
			map[aa][ab].push_back({ ad, key });
		}
		if (cnt == ac) {
			return;
		}
	}

	// À§ ¹Ø ¿Þ ¿À
	int x, y;
	for (int i = 0; i < 4; i++) {
		x = aa + dir[i][0];
		y = ab + dir[i][1];
		dfs(cnt + 1, x, y, ac, ad, key);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int m, a, temp;
	int aa, ab, ac, ad;
	for (int ii = 1; ii <= t; ii++) {
		cin >> m >> a;

		for (int i = 1; i < MAX; i++) {
			for (int j = 1; j < MAX; j++) {
				map[i][j].clear();
			}
		}
		amove.clear();
		bmove.clear();


		for (int i = 0; i < m; i++) {
			cin >> temp;
			amove.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			cin >> temp;
			bmove.push_back(temp);
		}

		for (int i = 0; i < a; i++) {
			cin >> aa >> ab >> ac >> ad;
			map[ab][aa].push_back({ ad, i });
			visit[ab][aa] = 1;
			dfs(0, ab, aa, ac, ad, i);
			memset(visit, 0, sizeof(visit));
		}

		int asum = 0, bsum = 0;
		int amax = 0, bmax = 0;
		if (!map[1][1].empty()) {
			for (int i = 0; i < map[1][1].size(); i++) {
				if (map[1][1][i].first > amax)
					amax = map[1][1][i].first;
			}
			asum += amax;
		}
		if (!map[10][10].empty()) {
			for (int i = 0; i < map[10][10].size(); i++) {
				if (map[10][10][i].first > bmax)
					bmax = map[10][10][i].first;
			}
			bsum += bmax;
		}

		int ax = 1, ay = 1, bx = 10, by = 10;
		int abc, bbc;
		int cut;
		for (int i = 0; i < m; i++) {
			amax = 0;
			bmax = 0;
			abc = -1;
			bbc = -2;
			
			ax += userdir[amove[i]][0];
			ay += userdir[amove[i]][1];

			bx += userdir[bmove[i]][0];
			by += userdir[bmove[i]][1];

			if (!map[ax][ay].empty()) {
				for (int j = 0; j < map[ax][ay].size(); j++) {
					if (map[ax][ay][j].first > amax) {
						amax = map[ax][ay][j].first;
						abc = map[ax][ay][j].second;
					}
				}
			}
			if (!map[bx][by].empty()) {
				for (int j = 0; j < map[bx][by].size(); j++) {
					if (map[bx][by][j].first > bmax) {
						bmax = map[bx][by][j].first;
						bbc = map[bx][by][j].second;
					}
				}
			}

			if (abc == bbc) {
				cut = abc;
				int pre = amax;
				amax = 0;
				bmax = 0;
				for (int j = 0; j < map[ax][ay].size(); j++) {
					if (map[ax][ay][j].first > amax) {
						if (map[ax][ay][j].second != cut) {
							amax = map[ax][ay][j].first;
							abc = map[ax][ay][j].second;
						}
					}
				}
				for (int j = 0; j < map[bx][by].size(); j++) {
					if (map[bx][by][j].first > bmax) {
						if (map[bx][by][j].second != cut) {
							bmax = map[bx][by][j].first;
							bbc = map[bx][by][j].second;
						}
					}
				}
				if (amax == 0 && bmax == 0) {
					asum += pre / 2;
					bsum += pre / 2;
				}
				else if (amax == 0) {
					asum += pre;
					bsum += bmax;
				}
				else if (bmax == 0) {
					asum += amax;
					bsum += pre;
				}
				else {
					if (amax >= bmax) {
						asum += amax;
						bsum += pre;
					}
					else {
						asum += pre;
						bsum += bmax;
					}
				}
			}
			else {
				asum += amax;
				bsum += bmax;
			}
		}

		cout << "#" << ii << " " << asum + bsum << endl;
	}


	return 0;
}