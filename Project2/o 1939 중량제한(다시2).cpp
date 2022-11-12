#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct pi {
	int e;
	int c;
};

bool visit[10001];
vector<pi> v[10001];

bool bfs(long long mid, int s, int e) {
	queue<int> q;
	q.push(s);
	memset(visit, 0, sizeof(visit));
	visit[s] = 1;

	while (!q.empty()) {
		s = q.front();
		q.pop();

		for (int i = 0; i < v[s].size(); i++) {
			int end = v[s][i].e;
			int cost = v[s][i].c;
			if (cost >= mid && visit[end] == 0) {
				if (end == e) {
					return true;
				}
				q.push(end);
				visit[end] = 1;
			}
		}
	}
	return false;
}


int main() {
	int n, m;
	cin >> n >> m;
	n++;


	long long max = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (v[a].size() == 0) {
			v[a].push_back({ b,c });
		}
		else {
			bool ok = true;
			for (int j = 0; j < v[a].size(); j++) {
				int aa = v[a][j].e;
				int bb = v[a][j].c;
				if (b == aa) {
					if (bb > c) {
						v[a][j].c = bb;
					}
					ok = false;
					break;
				}
			}
			if (ok) {
				v[a].push_back({ b,c });
			}
		}

		if (v[b].size() == 0) {
			v[b].push_back({ a,c });
		}
		else {
			bool ok = true;
			for (int j = 0; j < v[b].size(); j++) {
				int aa = v[b][j].e;
				int bb = v[b][j].c;
				if (a == aa) {
					if (bb > c) {
						v[b][j].c = bb;
					}
					ok = false;
					break;
				}
			}
			if (ok) {
				v[b].push_back({ a,c });
			}
		}

		
		if (max < c) {
			max = c;
		}
	}
	int s, e;
	cin >> s >> e;


	long long left = 1, right = max, result = 0, mid;
	while (left <= right) {
		mid = (left + right) / 2;

		if (bfs(mid, s, e)) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}