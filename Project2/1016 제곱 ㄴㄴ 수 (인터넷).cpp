#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

#define MAX 1000000

long long a, b;

bool map[MAX + 1];
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map[0] = map[1] = true;

	int rmax = sqrt((double)MAX) + 1.0;
	for (int i = a; i < rmax; i++) {
		if (map[i] == 0)
			for (int j = i + i; j <= MAX; j += i) {
				map[j] = true;
			}
	}

	for (int i = 2; i <= MAX; i++) {
		if (map[i] == false)
			prime.push_back(i);
	}

	memset(map, 0, sizeof(map));
	cin >> a >> b;
	// 최대 백만
	for (int i = 0; i < prime.size(); i++) {
		long long s = (long long)prime[i] * prime[i];
		if (s > b) break;
		long long j = (a % s) ? (a / s + 1) * s : a;
		for (; j <= b; j += s) {
			map[j - a] = true;
		}
	}
	int lm = b - a;
	int cnt = 0;
	for (int i = 0; i <= lm; i++) {
		if (map[i] == false) {
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}