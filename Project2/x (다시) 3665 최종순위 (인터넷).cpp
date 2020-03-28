#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define MAX 500+1

int t, n, m, a, b;
int input[MAX], map[MAX][MAX], in[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(map, 0, sizeof(map));
		memset(in, 0, sizeof(in));

		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> input[j];
		}

		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				map[input[j]][input[k]] = 1;
				in[input[k]]++;
			}
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (map[a][b]) {
				map[a][b] = 0;
				map[b][a] = 1;
				in[b]--;
				in[a]++;
			}
			else {
				map[a][b] = 1;
				map[b][a] = 0;
				in[b]++;
				in[a]--;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0)
				q.push(i);
		}

		bool ok = false;
		vector<int> result;
		while (!q.empty()) {
			if (q.size() > 1) {
				ok = true;
				break;
			}

			int cur = q.front();
			q.pop();
			result.push_back(cur);

			for (int j = 1; j <= n; j++) {
				if (map[cur][j]) {
					in[j]--;
					if (in[j] == 0)
						q.push(j);
				}
			}
		}

		if (ok) {
			cout << "?" << '\n';
		}
		else if (result.size() == n) {
			for (int j = 0; j < n; j++) {
				cout << result[j] << " ";
			}
			cout << '\n';
		}
		else
			cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}