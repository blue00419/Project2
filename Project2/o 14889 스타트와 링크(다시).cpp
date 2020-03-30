#include<iostream>
#include<cmath>

using namespace std;

#define MAX 20+1

int map[MAX][MAX];
bool visit[MAX];
static int minimum = 40000;

void dfs(int cnt, int start, int n) {
	if (cnt == n/2) {
		int s[MAX / 2] = { 0, }, l[MAX / 2] = { 0, };
		int scount = 0, lcount = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				s[scount] = i;
				scount++;
			}
			else {
				l[lcount] = i;
				lcount++;
			}
		}

		int ssum = 0, lsum = 0;
		for (int i = 0; i < n / 2 - 1; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				ssum += map[s[i]][s[j]];
				lsum += map[l[i]][l[j]];
			}
		}

		int sum = abs(ssum - lsum);
		if (minimum > sum)
			minimum = sum;
	}

	for (int i = start; i <= n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(cnt+1, i+1, n);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (i > j) {
				map[i][j] += map[j][i];
				map[j][i] = map[i][j];
			}
		}
	}

	dfs(0, 1, n);
	cout << minimum << '\n';

	return 0;
}