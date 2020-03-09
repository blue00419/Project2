#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<string.h>
#include<cmath>

using namespace std;

int n, k, t1, t2;
vector<pair<int, int> > v;
queue<pair<pair<int, int>, int> > q;
bool visit[1001];

bool bfs(int mid) {
	q.push({ {0,0}, 0 });
	
	int x, y, check;
	int mx, my;
	double dis;
	while (!q.empty()) {
		x = q.front().first.first;
		y= q.front().first.second;
		check = q.front().second;
		q.pop();

		for (int i = 0; i <= n; i++) {
			if (visit[i] == 0) {
				mx = v[i].first;
				my = v[i].second;

				dis = (abs(x - mx) * abs(x - mx)) + (abs(y - my) * abs(y - my));
				dis = sqrt(dis);
				if (dis - (int)dis == 0) {
					dis = dis / 10;
				}
				else {
					dis = (dis / 10) + 1;
				}
				int aa = (int)dis;
				if (aa <= mid) {
					if (check <= k && mx == 10000 && my == 10000) {
						while (!q.empty()) {
							q.pop();
						}
						return true;
					}
					q.push({ {mx, my}, check+1 });
					visit[i] = 1;
				}
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		v.push_back({ t1, t2 });
	}
	v.push_back({ 10000,10000 });

	double left = 1, right = 20000, temp, mid;
	int result = 2000;
	while (left <= right) {
		mid = (left + right) / 2;
		temp = sqrt(mid * mid * 2);
		if (temp - (int)temp == 0) {
			temp = temp / 10;
		}
		else {
			temp = (temp / 10) + 1;
		}

		memset(visit, false, sizeof(visit));
		if (bfs((int)temp)) {
			if(result > temp)
				result = temp;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << result << endl;

	return 0;
}