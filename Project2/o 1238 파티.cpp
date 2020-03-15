#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

#define MAX 1000+1

int n, m, x;
vector<pi> v[MAX];
priority_queue<pi, vector<pi>, greater<pi> > q;

bool visits[MAX][MAX];
int maps[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	int start, size;
	for (int j = 1; j <= n; j++) {
		while (!q.empty()) {
			q.pop();
		}
		start = j;
		q.push({ maps[j][j], j });
		while (!q.empty()) {
			start = q.top().second;
			q.pop();

			size = v[start].size();
			for (int i = 0; i < size; i++) {
				if (maps[j][start] + v[start][i].second < maps[j][v[start][i].first] ||
					maps[j][v[start][i].first] == 0) {
					if (visits[j][v[start][i].first] == 0) {
						maps[j][v[start][i].first] = maps[j][start] + v[start][i].second;
						q.push({ maps[j][v[start][i].first] , v[start][i].first });
					}
				}
			}
			visits[j][start] = 1;
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < maps[i][x] + maps[x][i]) {
			max = maps[i][x] + maps[x][i];
		}
	}
	
	printf("%d\n", max);

	return 0;
}