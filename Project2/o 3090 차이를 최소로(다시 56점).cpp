#include<iostream>

using namespace std;

#define MAX 100000+1

int n, t;
int map[MAX];
int result[MAX], comp[MAX];

bool calc(int mid) {
	int a, b, tcount=0;

	for (int i = 1; i <= n; i++) {
		comp[i] = map[i];
		if (i > 1) {
			a = comp[i - 1];
			b = comp[i];

			if (a - b > mid) {
				tcount += a - (b + mid);
				a = b + mid;
			}
			else if (b - a > mid) {
				tcount += b - (a + mid);
				b = a + mid;
			}
			comp[i - 1] = a;
			comp[i] = b;
		}
	}

	if (tcount <= t) {
		for (int i = 0; i <= n; i++) {
			result[i] = comp[i];
		}
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;

	int max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
		if (max < map[i])
			max = map[i];
	}

	int left = 1, right = MAX, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (calc(mid)) {
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}