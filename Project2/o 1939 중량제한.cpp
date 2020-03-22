#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

int n, m;
int a, b, c, s, e;
vector<int> map[10001];
bool visit[10001];

bool bfs(int mid) {
	queue<int> q;
	q.push(s);
	visit[s] = 1;

	int start, weight, end;
	while (!q.empty()) {
		start = q.front();
		q.pop();

		for (int i = 0; i < map[start].size()/2; i++) {
			weight = i * 2 + 1;
			end = i * 2;
			if (map[start][weight] >= mid && visit[map[start][end]] == 0) {
				if (map[start][end] == e) {
					return true;
				}
				q.push(map[start][end]);
				visit[map[start][end]] = 1;
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int max = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (max < c)
			max = c;
		map[a].push_back(b);
		map[a].push_back(c);
		map[b].push_back(a);
		map[b].push_back(c);
	}
	cin >> s >> e;

	long long left = 1, right = max, mid, result = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		memset(visit, false, sizeof(visit));

		if (bfs(mid)) {
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result << endl;

	return 0;
}