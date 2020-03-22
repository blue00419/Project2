#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, pair<int, int> > pi;

#define MAX 100+1

int n;
int map[MAX][MAX];
long long dp[MAX][MAX];
int dir[2][2] = {{0,1},{1,0}};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	
	dp[1][1] = 1;
	int mx, my;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n && j == n)
				break;
			
			for (int k = 0; k < 2; k++) {
				mx = i + map[i][j] * dir[k][0];
				my = j + map[i][j] * dir[k][1];

				if (mx > 0 && mx <= n && my > 0 && my <= n) {
					dp[mx][my] += dp[i][j];
				}
			}
		}
	}

	cout << dp[n][n] << '\n';

	return 0;
}