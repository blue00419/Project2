#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[10001][10001][1] = { 0, };
int a, b, c, s, e;
queue<int> q, v;
bool visit[10001];

int bfs(int mid) {
	q.push(1);
	visit[1] = 1;

	int max = 0;
	while (!q.empty()) {
		if (q.front() == e) {
			if (q.front() > max) {
				max = 
			}
		}

		for (int i = 1; i <= n; i++) {
			if (map[q.front()][i][0] != 0) {

			}
		}
	}

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
		if (map[a][b][0] < c) {
			map[a][b][0] = c;
		}
		if (map[b][a][0] < c) {
			map[b][a][0] = c; 
		}
	}
	cin >> s >> e;

	long long left = 1, right = max, mid, temp, result = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		temp = bfs(mid);
	}

	return 0;
}