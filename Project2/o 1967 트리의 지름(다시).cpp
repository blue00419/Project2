#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef struct vpi {
	int child;
	int weight;
};

typedef struct qpi {
	int start;
	int weight;
};

#define MAX 10000+1

int n;
vector<vpi> v[MAX];
queue<qpi> q;
bool visit[MAX];

vector<int> bfs(int s) {
	memset(visit, 0, sizeof(visit));
	q.push({ s, 0 });
	visit[s] = 1;

	int start, weight, size, max[2] = { 0, 0};
	while (!q.empty()) {
		start = q.front().start;
		weight = q.front().weight;
		q.pop();
		size = v[start].size();
		for (int i = 0; i < size; i++) {
			if (visit[v[start][i].child] == 0) {
				visit[v[start][i].child] = 1;
				q.push({ v[start][i].child , weight + v[start][i].weight});

				if (weight + v[start][i].weight > max[0]) {
					max[0] = weight + v[start][i].weight;
					max[1] = v[start][i].child;
				}
			}
		}
	}
	vector<int> result;
	result.push_back(max[0]);
	result.push_back(max[1]);
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b, c;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	vector<int> result = bfs(1);
	vector<int> result2 = bfs(result[1]);
	cout << result2[0] << endl;

	return 0;
}