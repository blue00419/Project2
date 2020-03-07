#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

#define MAX 2000000

int t;
long long a, b;
bool map[MAX + 1] = { 0, };
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int rmax = sqrt((double)MAX) + 1.0;
	for (int i = 2; i < rmax; i++) {
		if (map[i] == 0) {
			for (int j = i + i; j <= MAX; j = j + i) {
				map[j] = 1;
			}
		}
	}
	for (int i = 2; i <= MAX; i++) {
		if (map[i] == 0) {
			v.push_back(i);
			map[i] = i;
		}
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;

		a += b;
		if (a % 2 == 0) {
			printf("YES\n");
			continue;
		}
		// ¡¶ø£¿Â
	}

	return 0;
}