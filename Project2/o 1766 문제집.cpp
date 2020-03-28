#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX 32000+1

int n, m;
int map[MAX];
vector<int> v[MAX];
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[b]++;
		v[a].push_back(b);
	}

	int count = 0;
	while (1) {
		for (int i = 1; i <= n; i++) {
			if (map[i] == 0) {
				q.push(i);
				map[i] = -1;
				count++;
				break;
			}
		}

		int start, size;
		start = q.top();
		q.pop();

		cout << start << " ";
		size = v[start].size();
		for (int i = 0; i < size; i++) {
			map[v[start][i]]--;
		}
		if (count == n)
			break;
	}

	return 0;
}