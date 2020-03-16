#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, pair<int, int> > pi;

#define MAX 100+1

struct compare {
	bool operator()(pi x, pi y) {
		return x.first > y.first;
	}
};

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int booms[MAX][MAX];
priority_queue<pi, vector<pi>, compare > q;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	char temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	q.push({ 0, {1,1} });
	visit[1][1] = 1;
	int boom, x, y, mx, my;
	while (!q.empty()) {
		boom = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();

		if (x == n && y == m) {
			printf("%d\n", boom);
			break;
		}

		for (int i = 0; i < 4; i++) {
			mx = x + dir[i][0];
			my = y + dir[i][1];

			if (mx > 0 && mx <= n && my > 0 && my <= m) {
				if (visit[mx][my] == 0 || booms[mx][my] > boom) {
					visit[mx][my] = 1;
					if (map[mx][my] == 1) {
						if (booms[mx][my] != boom + 1) {
							booms[mx][my] = boom + 1;
							q.push({ boom + 1, {mx, my} });
						}
					}
					else {
						booms[mx][my] = boom;
						q.push({ boom, {mx, my} });
					}
				}
			}
		}
	}

	return 0;
}