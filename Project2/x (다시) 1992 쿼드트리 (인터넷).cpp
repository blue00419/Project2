#include<iostream>

using namespace std;

#define MAX 64

int n; // 2 4 8 16 32 64
int map[MAX][MAX] = { 0, };
char temp;
int visit[4] = { 0, };

void calc(int x, int y, int size) {

	bool ok = true;
	for (int i = x; (i < x + size) && ok; i++) {
		for (int j = y; (j < y + size) && ok; j++) {
			if (map[x][y] != map[i][j])
				ok = false;
		}
	}

	if (ok)
		printf("%d", map[x][y]);
	else {
		printf("(");
		calc(x, y, size / 2);
		calc(x, y + size / 2, size / 2);
		calc(x + size / 2, y, size / 2);
		calc(x + size / 2, y + size / 2, size / 2);
		printf(")");
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	calc(0,0,n);

	return 0;
}