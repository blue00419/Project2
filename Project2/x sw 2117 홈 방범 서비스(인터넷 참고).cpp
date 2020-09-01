#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>

using namespace std;

int map[20][20];
int cost[22];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

bool visit[20][20];

typedef pair<int, int> pi;

int bfs(int x, int y, int n, int m) {
	memset(visit, 0, sizeof(visit));
	queue<pi> q;
	visit[x][y] = 1;
	q.push({ x,y });

	int mx, my,count=0, size, k=1,result=0;
	if (map[x][y] == 1) {
		count++;
	}
	while (!q.empty()) {

		if (count * m >= cost[k]) {
			if (result < count) {
				result = count;
			}
		}

		if (k == n + 1) break;

		size = q.size();

		while (size--) {
			x = q.front().first;
			y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				mx = x + dir[i][0];
				my = y + dir[i][1];

				if (mx >= 0 && mx < 20 && my >= 0 && my < 20) {
					if (visit[mx][my] == 0) {
						visit[mx][my] = 1;
						q.push({ mx,my });
						if (map[mx][my] == 1) {
							count++;
						}
					}
				}
			}
		}

		k++;	
	}
	return result;
}

int main() {

	for (int i = 1; i < 22; i++) {
		cost[i] = i * i + (i - 1) * (i - 1);
	}

	int t;
	scanf("%d", &t);

	int n, m;
	for (int ii = 1; ii <= t; ii++) {
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int count = bfs(i, j, n, m);
				if (result < count) {
					result = count;
				}
			}
		}
		printf("#%d %d\n", ii, result);
	}

	return 0;
}