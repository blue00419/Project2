#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pi;

#define MAX 10000+1

int n;
vector<pi> v[MAX];
int map[MAX];
bool visit[MAX];

vector<int> bfs(int start) {
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(start);
	map[start] = 0;

	vector<int> max(2);
	int size;
	while (!q.empty()) {
		start = q.front();
		q.pop();

		size = v[start].size();
		for (int i = 0; i < size; i++) {
			if (visit[v[start][i].first] == 0) {
				q.push(v[start][i].first);
				map[v[start][i].first] = map[start] + v[start][i].second;
				if (map[v[start][i].first] > max[0]) {
					max[0] = map[v[start][i].first];
					max[1] = v[start][i].first;
				}
			}
		}
		visit[start] = 1;
	}

	return max;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	vector<int> result = bfs(1);
	vector<int> result2 = bfs(result[1]);
	cout << result2[0] << '\n';
}