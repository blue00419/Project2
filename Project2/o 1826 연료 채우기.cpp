#include<iostream>
#include<queue>

using namespace std;

int n, l, p, tm1, tm2;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  map;
priority_queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tm1 >> tm2;
		map.push({ tm1, tm2 });
	}
	cin >> l >> p;
	
	bool ok = false;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (p < map.top().first) {
			if (i == 1) {
				ok = true;
				break;
			}
			p += q.top();
			q.pop();
			count++;
			if (p < map.top().first) {
				while (!q.empty()) {
					p += q.top();
					q.pop();
					count++;
					if (p >= map.top().first) {
						break;
					}
				}
				if (p < map.top().first) {
					ok = true;
					break;
				}
			}
		}
		q.push(map.top().second);
		map.pop();
	}

	if (!ok) {
		while (p < l) {
			if (q.empty()) {
				ok = true;
				break;
			}
			p += q.top();
			q.pop();
			count++;
		}
	}

	if (ok)
		cout << "-1" << '\n';
	else
		cout << count << '\n';


	return 0;
}