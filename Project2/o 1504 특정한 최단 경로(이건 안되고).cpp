#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

typedef pair<int, int> pi;

#define MAX 800+1

int n, e;
bool visit[MAX];
int input[MAX][MAX] = { 0, };
int map[MAX];

void dijkstra(int start) {

	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));

	priority_queue<pi, vector<pi>, greater<pi> > q;

	map[start] = 0;
	q.push({ map[start], start });
	visit[start] = 1;
	while (!q.empty()) {
		start = q.top().second;
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 && (input[start][i] + map[start] < map[i] ||
				map[i] == 0) && input[start][i] != 0) {
				map[i] = input[start][i] + map[start];
				q.push({ map[i] , i });
			}
		}
		visit[start] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		if (input[a][b] == 0)
			input[a][b] = c;
		else if (input[a][b] != 0 && input[a][b] > c)
			input[a][b] = c;

		if (input[b][a] == 0)
			input[b][a] = c;
		else if (input[b][a] != 0 && input[b][a] > c)
			input[b][a] = c;
	}

	cin >> a >> b;
	n;

	int firstsum = 0, secondsum = 0;
	bool firststop = 0, secondstop = 0;

	// 1 -> a, b
	dijkstra(1);
	if (map[a] == 0)
		firststop=1;
	if (map[b] == 0)
		secondstop=1;

	firstsum += map[a];
	secondsum += map[b];


	// a -> b, n
	dijkstra(a);
	if (map[b] == 0)
		firststop = 1;
	if (map[n] == 0)
		secondstop = 1;

	firstsum += map[b];
	secondsum += map[n];


	// b -> n, a
	dijkstra(b);
	if (map[n] == 0)
		firststop = 1;
	if (map[a] == 0)
		secondstop = 1;

	firstsum += map[n];
	secondsum += map[a];


	if (firststop == 1 && secondstop == 1)
		cout << -1 << '\n';
	else if (firststop == 1)
		cout << secondsum << '\n';
	else if (secondstop == 1)
		cout << firstsum << '\n';
	else if (firststop == 0 && secondstop == 0)
		cout << min(firstsum, secondsum) << '\n';

	return 0;
}