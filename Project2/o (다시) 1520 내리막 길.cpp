#include<iostream>
#include<memory.h>

using namespace std;

#define MAX 500+1

int m, n;
int map[MAX][MAX];
int dp[MAX][MAX];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int calc(int x, int y) {
	
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 1 && y == 1) return 1;

	dp[x][y] = 0;
	int mx, my;
	for (int i = 0; i < 4; i++) {
		mx = x + dir[i][0];
		my = y + dir[i][1];
		if (x > 0 && x <= m && y > 0 && y <= n)
			if (map[mx][my] > map[x][y]) 
				dp[x][y] += calc(mx, my);
		
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << calc(m, n) << endl;
	return 0;
}