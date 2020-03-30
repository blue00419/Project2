#include<iostream>

using namespace std;

int map[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map[0] = 1;
	map[1] = 1;
	for (int i = 2; i < 1001; i++) {
		if (map[i] == 0) {
			for (int j = i + i; j < 1001; j = j + i)
				map[j] = 1;
		}
	}

	int n;
	cin >> n;

	int a, count=0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (map[a] == 0)
			count++;
	}
	cout << count << '\n';

	return 0;
}