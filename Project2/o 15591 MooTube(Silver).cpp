#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef struct pi {
	int end;
	int weight;
};

#define MAX 5000+1

vector<pi> v[MAX];
int n, q;
queue<pair<int, int> > check;
bool visit[MAX];

void bfs(int start, int weight) {
	memset(visit, 0, sizeof(visit));
	check.push({ start, weight });
	visit[start] = 1;

	int size;
	int count = 0;
	while (!check.empty()) {
		start = check.front().first;
		weight = check.front().second;
		check.pop();

		size = v[start].size();

		for (int i = 0; i < size; i++) {
			if (visit[v[start][i].end] == 0) {
				if (v[start][i].weight >= weight) {
					check.push({ v[start][i].end , weight });
					visit[v[start][i].end] = 1;
					count++;
				}
			}
		}
	}
	cout << count << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	int a, b, c;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		bfs(b, a);
	}

	return 0;
}