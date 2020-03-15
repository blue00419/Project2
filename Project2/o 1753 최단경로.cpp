#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

#define MAX 1000000

int map[20001];
vector<pi> input[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >,
	greater<pair<int, int> > > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int v, e; // 정점, 간선

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		map[i] = MAX;
	}

	int start;
	cin >> start;

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		input[a].push_back({ b, c });
	}

	int size;
	map[start] = 0;
	q.push({ map[start], start });
	while (!q.empty()) {
		start = q.top().second;
		q.pop();
		size = input[start].size();
		for (int i = 0; i < size; i++) {
			if (map[start] + input[start][i].second < map[input[start][i].first]) {
				map[input[start][i].first] =
					min(map[start] + input[start][i].second,
						map[input[start][i].first]);
				q.push({ map[input[start][i].first], input[start][i].first });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (map[i] == MAX) {
			printf("INF\n");
		}
		else
			printf("%d\n", map[i]);
	}
	
	return 0;
}