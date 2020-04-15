#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define MAX 1000+1

typedef pair<int, int> pi;

bool visit[MAX];

int bfs(int start, vector<int>* map) {
	queue<pi> q;
	visit[start] = 1;
	q.push({ start, 0 });

	int count, size, sum=0;
	while (!q.empty()) {
		start = q.front().first;
		count = q.front().second;
		q.pop();

		size = map[start].size();

		for (int i = 0; i < size; i++) {
			if (visit[map[start][i]] == 0) {
				visit[map[start][i]] = 1;
				q.push({ map[start][i], count + 1 });
				sum += count + 1;
			}
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int n, a;
		cin >> n;

		vector<int> map[MAX];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a;
				if (a == 1) {
					map[i].push_back(j);
				}
			}
		}

		int min = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) {
			int result = bfs(i, map);
			memset(visit, 0, sizeof(visit));

			if (min > result)
				min = result;
		}
		cout << "#" << ii << " " << min << endl;
	}

	return 0;
}