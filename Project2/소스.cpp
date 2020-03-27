#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define MAX 1000+1

int t, n, k, w;
vector<int> v[MAX], check[MAX];
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
			cin >> cost[j];
		}

		int a, b;
		for (int j = 0; j < k; j++) {
			cin >> a >> b;
			v[a].push_back(b);
			check[b].push_back(a);
			map[b]++;
		}

		cin >> w;

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
						if (check[v[q.front()][j]][ii] == q.front()) {
							check[v[q.front()][j]][ii] = 0;
							map[v[q.front()][j]]--;
						}
					}

					for (int ii = 0; ii < size2; ii++) {
						if (check[v[q.front()][j]][ii] == 0) {
							c++;
						}
					}

					if (c == size2) {
						cost[v[q.front()][j]] += cost[q.front()];
					}
				}
				q.pop();
			}
			if (map[w]==0)
				break;
		}
		cout << cost[w] << endl;
	}
	return 0;
}