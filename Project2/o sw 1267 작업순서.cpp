#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

#define MAX 1000+1

int map[MAX];
vector<int> vv[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 10;
	//cin >> t;

	for (int ii = 1; ii <= t; ii++) {
		int v, e;
		cin >> v >> e;

		memset(map, 0, sizeof(map));

		for (int i = 1; i <= v; i++) {
			vv[i].clear();
		}

		int a, b;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			vv[a].push_back(b);
			map[b]++;
		}

		cout << "#" << ii;
		int count = 0, start;
		queue<int> q;
		while (1) {
			for (int i = 1; i <= v; i++) {
				if (map[i] == 0) {
					q.push(i);
					count++;
					map[i] = -1;
				}
			}

			while (!q.empty()) {
				start = q.front();
				q.pop();
				cout << " " << start;

				for (int i = 0; i < vv[start].size(); i++) {
					map[vv[start][i]]--;
				}
			}


			if (count == v)
				break;
		}
		cout << endl;
	}

	return 0;
}