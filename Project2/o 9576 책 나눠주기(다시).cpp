#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int > pi;

#define MAX 1000+1

int t, n, m;
priority_queue<pi, vector<pi>, greater<pi> > q;
bool visit[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> n >> m; // Ã¥, »ç¶÷

		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			q.push({b, a});
		}

		memset(visit, 0, sizeof(visit));
		int count = 0;
		for (int j = 0; j < m; j++) {
			b = q.top().first;
			a = q.top().second;
			q.pop();
			for (int k = a; k <= b; k++) {
				if (visit[k] == 0) {
					visit[k] = 1;
					count++;
					break;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}