#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

#define MAX 1000+1

int t, n, k, w;
vector<int> v[MAX]; 
vector<pair<int, int> > check[MAX];
queue<int> q;
int cost[MAX];
int map[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> k;

		for (int j = 1; j <= n; j++) {
			v[j].clear();
			check[j].clear();
		}
		memset(cost, 0, sizeof(cost));
		memset(map, 0, sizeof(map));

		for (int j = 1; j <= n; j++) {
			cin >> cost[j];
		}

		int a, b;
		for (int j = 0; j < k; j++) {
			cin >> a >> b;
			v[a].push_back(b);
			check[b].push_back({ a, 0 });
			map[b]++;
		}

		cin >> w;

		if (check[w].size() == 0) {
			cout << cost[w] << '\n';
		}
		else {

			while (1) {
				for (int j = 1; j <= n; j++) {
					if (map[j] == 0) {
						q.push(j);
						map[j] = -1;
					}
				}
				int size, size2;
				while (!q.empty()) {
					size = v[q.front()].size();

					for (int j = 0; j < size; j++) {
						size2 = check[v[q.front()][j]].size();
						int c = 0;

						for (int ii = 0; ii < size2; ii++) {
							if (check[v[q.front()][j]][ii].first == q.front()) {
								if (check[v[q.front()][j]][ii].second == 0) {
									check[v[q.front()][j]][ii].second = 1;
									map[v[q.front()][j]]--;
								}
							}
						}

						int max = 0;
						for (int ii = 0; ii < size2; ii++) {
							if (check[v[q.front()][j]][ii].second == 1) {
								c++;
								if (cost[check[v[q.front()][j]][ii].first] > max)
									max = cost[check[v[q.front()][j]][ii].first];
							}
						}

						if (c == size2) {
							cost[v[q.front()][j]] = cost[v[q.front()][j]] + max;
						}
					}
					q.pop();
				}
				if (map[w] == 0)
					break;
			}

			while (!q.empty())
				q.pop();
			cout << cost[w] << endl;
		}
	}
	return 0;
}