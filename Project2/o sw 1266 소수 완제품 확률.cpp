#include<iostream>

using namespace std;

#define MAX 18+1

double amap[MAX], bmap[MAX];
long long pac[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	pac[0] = 1;
	for (int i = 1; i < MAX; i++) {
		pac[i] = pac[i - 1] * i;
	}

	for (int ii = 1; ii <= t; ii++) {
		for (int i = 0; i < MAX; i++) {
			amap[i] = (pac[18] / (pac[18 - i] * pac[i]));
			bmap[i] = (pac[18] / (pac[18 - i] * pac[i]));
		}

		double a, b;
		cin >> a >> b;
		a /= 100;
		b /= 100;
		
		double as=1, bs=1;
		for (int i = 1; i < MAX; i++) {
			as *= a;
			bs *= b;
			amap[i] *= as;
			bmap[i] *= bs;
		}


		as = 1, bs = 1;
		for (int i = MAX-2; i>=0; i--) {
			as *= (1.0-a);
			bs *= (1.0-b);
			amap[i] *= as;
			bmap[i] *= bs;
		}

		double result = 0;
		// 2 3 5 7 11 13 17
		result = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (i == 2 || i == 3 || i == 5 ||
					i == 7 || i == 11 || i == 13 || i == 17) {
					if (j != 2 && j != 3 && j != 5 &&
						j != 7 && j != 11 && j != 13 && j != 17) {
						result += amap[i] * bmap[j];
					}
				}
			}
		}

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (i == 2 || i == 3 || i == 5 ||
					i == 7 || i == 11 || i == 13 || i == 17) {
					if (j != 2 && j != 3 && j != 5 &&
						j != 7 && j != 11 && j != 13 && j != 17) {
						result += bmap[i] * amap[j];
					}
				}
			}
		}

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (i == 2 || i == 3 || i == 5 ||
					i == 7 || i == 11 || i == 13 || i == 17) {
					if (j == 2 || j == 3 || j == 5 ||
						j == 7 || j == 11 || j == 13 || j == 17) {
						result += bmap[i] * amap[j];
					}
				}
			}
		}

		double result2 = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				result2 += (amap[i] * bmap[j]);
			}
		}

		printf("#%d %.6f\n", ii, result / result2);
	}

	return 0;
}