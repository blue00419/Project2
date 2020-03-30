#include<iostream>

using namespace std;

#define MAX 10000+1

int map[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		map[a]++;
	}
	for (int i = 1; i < MAX; i++) {
		if (map[i] != 0) {
			for (int j = 0; j < map[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}