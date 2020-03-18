#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

#define MAX 10000+1

int n, m;
int s, e;
bool visit[MAX];
vector<pi> map[MAX];
queue<int> q;

bool bfs(int mid) {
	memset(visit, 0, sizeof(visit));

	q.push(s);
	visit[s] = 1;

	int start,size;
	while (!q.empty()) {
		start = q.front();
		q.pop();


		size = map[start].size();
		for (int i = 0; i < size; i++) {
			if (map[start][i].second >= mid && visit[map[start][i].first] == 0) {
				if (map[start][i].first == e) {
					while (!q.empty())
						q.pop();
					return true;
				}
				q.push(map[start][i].first);
				visit[map[start][i].first] = 1;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b, c, max=0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });

		if (max < c)
			max = c;
	}

	cin >> s >> e;

	long long left = 1, right = max, mid, result = 0;
	while (left <= right) {
		mid = (left + right) / 2;

		if (bfs(mid)) {
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result << '\n';

	return 0;
}