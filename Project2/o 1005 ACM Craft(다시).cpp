#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define MAX 1000+1

int t, n, k, a, b ,w;
int map[MAX];
vector<int> time, result;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int ii = 0; ii < t; ii++) {
		memset(map, 0, sizeof(map));
		time.clear();
		result.clear();
		vector<int> v[MAX];

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a;
			time.push_back(a);
			result.push_back(a);
		}

		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			map[b]++;
		}

		cin >> w;

		queue<pair<int, int> > q;
		while (1) {
			if (map[w] == 0) {
				cout << result[w - 1] << '\n';
				break;
			}
			for (int i = 1; i <= n; i++) {
				if (map[i] == 0) {
					q.push({ i, result[i-1] });
					map[i] = -1;
				}
			}

			int start, size, timer;
			while (!q.empty()) {
				start = q.front().first;
				timer = q.front().second;
				q.pop();

				size = v[start].size();
				for (int i = 0; i < size; i++) {
					map[v[start][i]]--;
					if (result[v[start][i] - 1] < timer + time[v[start][i] - 1]) {
						result[v[start][i] - 1] = timer + time[v[start][i] - 1];
					}
				}
			}

		}
	}

	return 0;
}