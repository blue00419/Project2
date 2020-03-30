#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

#define MAX 50

int n, m;
int map[MAX][MAX];
vector<pi> h, c;
vector<int> ch[13];
bool visit[13];
static int minimum = 2000;

void dis() {
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < h.size(); j++) {
			int a = abs(c[i].first - h[j].first);
			int b = abs(c[i].second - h[j].second);
			ch[i].push_back(a + b);
		}
	}
}

void dfs(int cnt, int start) {
	if (cnt == m) {
		vector<int> check;
		for (int i = 0; i < 13; i++) {
			if (visit[i] == 1) {
				check.push_back(i);
			}
		}
		int min, sum=0;
		for (int i = 0; i < h.size(); i++) {
			min = 100;
			for (int j = 0; j < check.size(); j++) {
				if (min > ch[check[j]][i])
					min = ch[check[j]][i];
			}
			sum += min;
		}

		if (minimum > sum)
			minimum = sum;

	}

	for (int i = start; i < c.size(); i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(cnt + 1, i);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				h.push_back({ i,j });
			else if (map[i][j] == 2)
				c.push_back({ i,j });
		}
	}

	dis();
	dfs(0, 0);
	cout << minimum << endl;

	return 0;
}