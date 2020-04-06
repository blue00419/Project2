#include<iostream>

using namespace std;

#define MAX 1000

int map[MAX];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 10;

	for (int ii = 1; ii <= t; ii++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}

		int count = 0;
		int gijun, a, b, c, d, max;
		for (int i = 2; i < n - 2; i++) {
			gijun = map[i];
			a = map[i - 1];
			b = map[i - 2];
			c = map[i + 1];
			d = map[i + 2];
			max = a;
			if (gijun > a&& gijun > b&& gijun > c&& gijun > d) {
				if (max < b)
					max = b;
				if (max < c)
					max = c;
				if (max < d)
					max = d;
				count += gijun - max;
			}
		}
		cout << "#" << ii << " " <<count << endl;
	}

	return 0;
}