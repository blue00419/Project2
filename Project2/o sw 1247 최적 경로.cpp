#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int sp[2], ep[2];
bool visit[10];
int map[10];
static int minimum;
vector<pair<int, int> > v;

void dfs(int cnt, int n) {
	if (cnt == n) {
		int sum = 0;
		int ap[2] = { sp[0], sp[1] };
		for (int i = 0; i < n; i++) {
			sum += abs(ap[0] - v[map[i]].first) +
				abs(ap[1] - v[map[i]].second);
			ap[0] = v[map[i]].first;
			ap[1] = v[map[i]].second;
		}
		sum += abs(ap[0] - ep[0]) +
			abs(ap[1] - ep[1]);
		if (minimum > sum)
			minimum = sum;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			map[cnt] = i;
			dfs(cnt + 1, n);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int n, a, b;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		memset(visit, 0, sizeof(visit));
		v.clear();
		minimum = 3000;

		cin >> sp[0] >> sp[1];
		cin >> ep[0] >> ep[1];

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}

		dfs(0, n);
		cout << "#" << ii << " " << minimum << endl;
	}

	return 0;
}