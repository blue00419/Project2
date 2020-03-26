#include<iostream>
#include<vector>

using namespace std;

#define MAX 400+1

int n, k;
int dp[MAX][MAX];
int s;
vector<pair<int, int> > v;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		dp[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][i] && dp[i][k]) dp[j][k] = 1;
			}
		}
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < s; i++) {
		if (dp[v[i].first][v[i].second] && !dp[v[i].second][v[i].first])
			cout << -1 << '\n';
		else if (dp[v[i].second][v[i].first] && !dp[v[i].first][v[i].second])
			cout << 1 << '\n';
		else if (!dp[v[i].second][v[i].first] && !dp[v[i].first][v[i].second])
			cout << 0 << '\n';
	}

	return 0;
}