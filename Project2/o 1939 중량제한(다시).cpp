#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define MAX 10000+1

typedef pair<int, int> pi;

int n, m;
int s, e;
vector<pi> v[MAX];
bool visit[MAX];

bool calc(int mid) {
	queue<int> q;
	q.push(s);
	visit[s] = 1;

	int size, start;
	while (!q.empty()) {
		start = q.front();
		q.pop();

		size = v[start].size();
		for (int i = 0; i < size; i++) {
			if (v[start][i].second >= mid && visit[v[start][i].first] == 0) {
				if (v[start][i].first == e) {
					return true;
				}
				q.push(v[start][i].first);
				visit[v[start][i].first] = 1;
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
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		if (max < c)
			max = c;
	}
	cin >> s >> e;

	long long left = 1, right = max, mid, result = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		memset(visit, false, sizeof(visit));

		if (calc(mid)) {
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << result << '\n';

	return 0;
}