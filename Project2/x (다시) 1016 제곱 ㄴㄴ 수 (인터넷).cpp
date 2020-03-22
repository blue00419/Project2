#include<iostream>
#include<cmath>

using namespace std;

#define MAX 1000000
bool map[MAX + 1];
int other[MAX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long min, max;
	cin >> min >> max;

	int rmax = sqrt((double)MAX) + 1;
	for (int i = 2; i < rmax; i++) {
		if (map[i] == 0) {
			for (int j = i + i; j <= MAX; j = j + i) {
				map[j] = 1;
			}
		}
	}

	int count = 0;
	for (int i = 2; i <= MAX; i++) {
		if (map[i] == 0) {
			other[count] = i;
			count++;
		}
		map[i] = 0;
	}

	int result = 0;

	for (int i = 0; i < count; i++) {
		long long s = (long long)other[i] * other[i];
		if (s > max)
			break;

		long long div_min = min;
		if (div_min % s != 0) {
			div_min = (div_min / s + 1) * s;
		}

		for (long long j = div_min; j <= max; j += s) {
			if (!map[j - min]) {
				map[j - min] = 1;
				result++;
			}
		}
	}

	cout << max - min + 1 - result << '\n';
	return 0;
}