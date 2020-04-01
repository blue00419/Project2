#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 10+1

int n, m, k;
int map[MAX][MAX];
int w[MAX][MAX];
int dir[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };

vector<int> tree[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 5;
			cin >> w[i][j];
		}
	}
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
	}

	int food, foodsum;
	int size;
	int mx, my;
	int count = 0;
	for (int ii = 0; ii < k; ii++) {

		// 봄, 여름
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!tree[i][j].empty()) {
					food = map[i][j];
					size = tree[i][j].size();
					foodsum = 0;

					bool ok = true;
					int end = -1;
					for (int k = size - 1; k >= 0; k--) {
						if (tree[i][j][k] <= food) {
							food -= tree[i][j][k];
							tree[i][j][k]++;
						}
						else {
							if (ok)
								end = k;
							ok = false;
							foodsum += (int)(tree[i][j][k] / 2);
						}
					}
					
					if(end != -1){
						tree[i][j].erase(tree[i][j].begin(), tree[i][j].begin()+end+1);
					}
					map[i][j] = food + foodsum;
				}
			}
		}

		// 가을
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!tree[i][j].empty()) {
					size = tree[i][j].size();

					for (int k = 0; k < size; k++) {
						if (tree[i][j][k] % 5 == 0) {

							for (int ii = 0; ii < 8; ii++) {
								mx = i + dir[ii][0];
								my = j + dir[ii][1];

								if (mx > 0 && mx <= n && my > 0 && my <= n) {
									tree[mx][my].push_back(1);
								}
							}
						}
					}
				}
			}
		}

		// 겨울
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] += w[i][j];
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += tree[i][j].size();
		}
	}
	cout << sum << '\n';

	return 0;
}