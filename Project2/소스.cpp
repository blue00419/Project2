#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

typedef pair<int, int> pi;

#define MAX 800+1

int INF = 987654321;

int n, e;
bool visit[MAX];
int input[MAX][MAX] = { 0, };

vector<int> dijkstra(int start, int end, int first, int second) {

	vector<int> map(end+1, INF);
	memset(visit, 0, sizeof(visit));

	priority_queue<pi, vector<pi>, greater<pi> > q;

	map[start] = 0;
	q.push({ map[start], start });
	visit[start] = 1;
	while (!q.empty()) {
		start = q.top().second;
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 && input[start][i] + map[start] < map[i]) {
				map[i] = input[start][i] + map[start];
				q.push({ map[i] , i });
			}
		}
		visit[start] = 1;
	}

	vector<int> result = { map[first], map[second] };

	return result;
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

	int firstsum = 0, secondsum = 0;
	vector<int> z = dijkstra(1, n, a, b);
	firstsum += z[0];
	secondsum += z[1];

	vector<int> zz = dijkstra(a, n, b, n);
	firstsum += zz[0];
	secondsum += zz[1];

	vector<int> zzz = dijkstra(b, n, n, a);
	firstsum += zzz[0];
	secondsum += zzz[1];

	int aa = min(firstsum, secondsum);
	if (aa >= INF || aa < 0) 
		cout << '-1' << '\n';
	else
		cout << aa << '\n';

	return 0;
}