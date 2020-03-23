#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

typedef pair<int, int > pi;

#define MAX 800+1
#define INF 1000000

vector<pi> map[MAX];
int v[3][MAX];

int* calc(int s, int n, int cnt) {
	priority_queue<pi, vector<pi>, greater<pi> > q;
	bool visit[MAX] = { 0, };
	memset(v[cnt], INF, sizeof(v[cnt]));
	q.push({ 0, s });

	int w, size, count=0;
	while (!q.empty()) {
		w = q.top().first;
		s = q.top().second;
		q.pop();

		if (visit[s] == 0) {
			count++;
			v[cnt][s] = w;
			if (count == n)
				return v[cnt];
		}

		size = map[s].size();
		for (int i = 0; i < size; i++) {
			if (visit[map[s][i].first] == 0) {
				q.push({ w + map[s][i].second, map[s][i].first });
			}
		}
		visit[s] = 1;
	}
	return v[cnt];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, e;
	cin >> n >> e;
	
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}

	int p1, p2;
	cin >> p1 >> p2;

	calc(1, n, 0);
	calc(p1, n, 1);
	calc(p2, n, 2);

	int minimum = min(v[0][p1] + v[1][p2] + v[2][n], v[0][p2] + v[2][p1] + v[1][n]);

	if (minimum >= INF || minimum < 0) {
		cout << -1 << endl;
	}
	else
		cout << minimum << endl;
	return 0;
}