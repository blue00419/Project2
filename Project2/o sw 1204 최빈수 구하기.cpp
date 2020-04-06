#include<iostream>
#include<cstring>

using namespace std;

#define MAX 100+1

int map[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		memset(map, 0, sizeof(map));

		int a;
		for (int i = 0; i < 1000; i++) {
			cin >> a;
			map[a]++;
		}
		int max = 0;
		int result = 0;
		for (int i = 0; i < MAX; i++) {
			if (max <= map[i]) {
				max = map[i];
				result = i;
			}
		}
		cout << "#" << n << " " << result << '\n';
	}

	return 0;
}