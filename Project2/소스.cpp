#include<iostream>
#include<queue>

using namespace std;

#define MAX 1000000+1

int n;
int map[MAX], dp[MAX];
priority_queue<pair<int, int> > q, suv;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}

	q.push({ 1, 10 });
	int max, x, allmax=0;
	for (int i = 2; i <= n; i++) {
		while (!q.empty()) {
			max = q.top().first;
			x = q.top().second;
			q.pop();
			suv.push({ max, x });
			if (x < map[i]) {
				break;
			}
		}
		dp[i] = max + 1;
		while (!suv.empty()) {
			max = suv.top().first;
			x = suv.top().second;
			suv.pop();
			q.push({ max, x });
		}
		q.push({ dp[i], map[i] });
		if (allmax < dp[i])
			allmax = dp[i];
	}
	cout << allmax << '\n';

	return 0;
}