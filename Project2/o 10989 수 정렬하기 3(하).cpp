#include<iostream>

using namespace std;

int map[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		map[temp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < map[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}