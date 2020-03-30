#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

bool compare(pi& a, pi& b) {
	if (a.first > b.first)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	int n, m, a, count;
	vector<pi> v;
	queue<pi> q;
	for (int i = 0; i < t; i++) {
		int map[10] = { 0, };
		count = 0;

		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> a;
			q.push({ a,j });
			map[a]++;
		}

		for (int j = 9; j >0; j--) {
			if (map[j] != 0) {
				while (1) {
					if (q.front().first == j) {
						count++;
						if (q.front().second == m) {
							cout << count << '\n';
						}
						map[j]--;
						q.pop();
						if (map[j] == 0)
							break;
					}
					else {
						q.push({ q.front().first,q.front().second });
						q.pop();
					}
				}
			}
		}
	}

	return 0;
}