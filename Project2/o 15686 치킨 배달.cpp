#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int map[51][51];
int h[101][2], c[14][2], ch[14][101];
int hcount = 1, ccount = 1;
bool visit[14];
static int allsum = 100000000;

void dfs(int cur, int cnt) {
	if (cnt == m) {
		vector<int> v;

		for (int i = 1; i < 14; i++) {
			if (visit[i] == 1) {
				v.push_back(i);
			}
		}

		int min, temp=0;
		for (int i = 1; i < hcount; i++) {
			min = 1000;
			for (int j = 0; j < v.size(); j++) {
				if (ch[v[j]][i] < min) {
					min = ch[v[j]][i];
				}
			}
			temp += min;
		}

		if (allsum > temp) {
			allsum = temp;
		}
		return;
	}

	for (int i = cur; i < ccount; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(i, cnt + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				h[hcount][0] = i;
				h[hcount][1] = j;
				hcount++;
			}
			else if (map[i][j] == 2) {
				c[ccount][0] = i;
				c[ccount][1] = j;
				ccount++;
			}
		}
	}

	for (int i = 1; i < ccount; i++) {
		for (int j = 1; j < hcount; j++) {
			ch[i][j] = abs(c[i][0] - h[j][0])
				+ abs(c[i][1] - h[j][1]);
		}
	}

	dfs(1, 0);
	cout << allsum << endl;
	return 0;
}