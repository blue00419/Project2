#include<iostream>

using namespace std;

int map[1002][1002];

int main() {
	int n, k;
	cin >> n >> k;

	map[1][1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= i; j++) {
			map[i][j] = (map[i - 1][j - 1] + map[i - 1][j])%10007;
		}
	}
	cout << map[n + 1][k + 1];
}