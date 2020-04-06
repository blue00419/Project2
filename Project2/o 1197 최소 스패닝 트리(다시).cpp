#include<iostream>
#include<queue>

using namespace std;

#define MAX 10000+1

typedef pair<int, pair<int, int> > pi;

int v, e;
int a, b, c;
priority_queue<pi, vector<pi>, greater<pi> > q;
int map[MAX];

int find(int x) {
	if (x == map[x]) return x;
	int y = find(map[x]);
	map[x] = y;
	return y;
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	map[y] = x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		q.push({ c, {a,b} });
	}

	for (int i = 1; i <= v; i++) {
		map[i] = i;
	}

	int weight, start, end, sum = 0;
	while (!q.empty()) {
		weight = q.top().first;
		start = q.top().second.first;
		end = q.top().second.second;
		q.pop();

		if (find(start) != find(end)) {
			Union(start, end);
			sum += weight;
		}
	}
	cout << sum << '\n';
	return 0;
}