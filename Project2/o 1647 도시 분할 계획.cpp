#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, pair<int, int> > pi;

#define MAX 100000+1

int n, m;
int map[MAX];
priority_queue<pi, vector<pi>, greater<pi> > q;

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

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		map[i] = i;
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		q.push({ c, {a,b} });
	}

	int weight, start, end, sum=0, last;
	while (!q.empty()) {
		weight = q.top().first;
		start = q.top().second.first;
		end = q.top().second.second;
		q.pop();

		if (find(start) != find(end)) {
			Union(start, end);
			sum += weight;
			last = weight;
		}
	}
	cout << sum - last << '\n';

	return 0;
}