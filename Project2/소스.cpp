#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

struct pi {
	int x;
	int time;
};

vector<pi> v[1001];
bool visit[1001];
static int minn;

void dfs(int start, int end, int time) {
	if (start == end) {
		if (minn > time) {
			minn = time;
		}
		return;
	}

	for (int i = 0; i < v[start].size(); i++) {
		int a = v[start][i].x;
		int b = v[start][i].time;
		if (visit[a] == 0) {
			visit[a] = 1;
			dfs(a, end, time + b);
			visit[a] = 0;
		}
	}
}

int main() {
	int n, m, x;
	cin >> n >> m >> x;


	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		minn = 100000;
		memset(visit, 0, sizeof(visit));
		visit[i] = 1;
		dfs(i, x, 0);
		int tmp1 = minn;

		minn = 100000;
		memset(visit, 0, sizeof(visit));
		visit[x] = 1;
		dfs(x, i, 0);
		int tmp2 = minn;

		int tmp = tmp1 + tmp2;
		if (max < tmp) {
			max = tmp;
		}
	}
	cout << max << endl;
}