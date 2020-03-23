#include<iostream>

using namespace std;

#define MAX 64+1

int n;
int map[MAX][MAX];

void calc(int x, int y,int cnt) {
	int count = 0;
	for (int i = x; i < x + cnt; i++) {
		for (int j = y; j < y + cnt; j++) {
			if (map[i][j] == 1)
				count++;
		}
	}

	if (count == (cnt * cnt)) {
		cout << "1";
	}
	else if (count == 0) {
		cout << "0";
	}
	else {
		cout << "(";
		int half = cnt / 2;
		calc(x, y, half);
		calc(x, y + half, half);
		calc(x + half, y, half);
		calc(x + half, y + half, half);
		cout << ")";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	char temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	calc(1,1,n);

	return 0;
}