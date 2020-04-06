#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAX 200000+1

typedef pair<int, int> pi;

int c, b;
vector<int> v;
queue<pi> q;
bool visit[MAX][2];

void bfs(int start) {
	q.push({ 0, start });
	if (start % 2 == 0) {
		visit[start][0] = 1;
	}
	else {
		visit[start][1] = 1;
	}

	int time;
	while (!q.empty()) {
		time = q.front().first;
		start = q.front().second;
		q.pop();

		if (time >= v.size())
			break;
		if (v[time] == start) {
			cout << time << '\n';
			return;
		}

		if (start + 1 < MAX) {
			if (time % 2 == 0) {
				if (visit[start + 1][0] == 0) {
					q.push({ time + 1, start + 1 });
					visit[start + 1][0] = 1;
				}
			}
			else {
				if (visit[start + 1][1] == 0) {
					q.push({ time + 1, start + 1 });
					visit[start + 1][1] = 1;
				}
			}
		}
		if (start - 1 >= 0) {
			if (time % 2 == 0) {
				if (visit[start - 1][0] == 0) {
					q.push({ time + 1, start - 1 });
					visit[start - 1][0] = 1;
				}
			}
			else {
				if (visit[start - 1][1] == 0) {
					q.push({ time + 1, start - 1 });
					visit[start - 1][1] = 1;
				}
			}
		}
		if (start * 2 < MAX) {
			if (time % 2 == 0) {
				if (visit[start * 2][0] == 0) {
					q.push({ time + 1, start * 2 });
					visit[start * 2][0] = 1;
				}
			}
			else {
				if (visit[start * 2][1] == 0) {
					q.push({ time + 1, start * 2 });
					visit[start * 2][1] = 1;
				}
			}
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> b;

	int a = 0;
	while (1) {
		c += a;
		if (c > MAX - 1)
			break;
		v.push_back(c);
		a++;
	}

	bfs(b);

	return 0;
}