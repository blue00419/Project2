#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

#define MAX 100
int map[MAX][2];

bool bfs(int start, int end) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		start = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			if (map[start][i] != 0) {
				if (map[start][i] == end) {
					return true;
				}
				q.push(map[start][i]);
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int n, m;
	int a, b;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n >> m;
		memset(map, 0, sizeof(map));

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (map[a][0] == 0)
				map[a][0] = b;
			else
				map[a][1] = b;
		}

		bool ok = bfs(0, 99);

		cout << "#" << ii << " " << ok << endl;
	}

	return 0;
}