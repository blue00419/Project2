#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX 100 + 1

int n, s;
vector<int> v[MAX];
bool visit[MAX];
queue<pair<int, int> > q;
priority_queue<int> result;

void bfs(int cnt) {
	visit[s] = 1;
	q.push({ 0,s });

	int count, start, gijun=-1;
	while (!q.empty()) {
		count = q.front().first;
		start = q.front().second;
		q.pop();
		if (count != gijun) {
			gijun = count;
			while (!result.empty()) {
				result.pop();
			}
		}
		result.push(start);

		for (int i = 0; i < v[start].size(); i++) {
			if (visit[v[start][i]] == 0) {
				visit[v[start][i]] = 1;
				q.push({ count + 1, v[start][i] });
			}
		}
	}
	cout << "#"<< cnt << " " << result.top() << endl;

	while (!result.empty()) {
		result.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	int a, b;
	for (int ii = 1; ii <= t; ii++) {
		cin >> n >> s;
		for (int i = 0; i < n / 2; i++) {
			cin >> a >> b;
			v[a].push_back(b);
		}

		bfs(ii);

		for (int i = 0; i < MAX; i++) {
			if(!v[i].empty())
				v[i].clear();
			visit[i] = 0;
		}

	}

	return 0;
}