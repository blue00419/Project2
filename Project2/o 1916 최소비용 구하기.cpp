#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

#define MAX 1000+1

int n, m;
vector<pi> v[MAX];
long long map[MAX];
priority_queue<pi, vector<pi>, greater<pi> > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		map[i] = -1;
	}

	int start, end;
	cin >> start >> end;

	int size;
	map[start] = 0;
	q.push({ map[start], start });
	while (!q.empty()) {
		start = q.top().second;
		q.pop();

		size = v[start].size();

		for (int i = 0; i < size; i++) {
			if (map[start] + v[start][i].second < map[v[start][i].first] ||
				map[v[start][i].first] == -1) {
				map[v[start][i].first] = map[start] + v[start][i].second;
				q.push({ map[v[start][i].first] ,
					v[start][i].first });
			}
		}
	}

	printf("%lld\n", map[end]);
	return 0;
}