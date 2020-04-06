#include<iostream>

using namespace std;

#define MAX 100

int map[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		int sum, max =0;
		for (int j = 0; j < MAX; j++) {
			sum = 0;
			for (int k = 0; k < MAX; k++) {
				cin >> map[j][k];
				sum += map[j][k];
			}
			if (max < sum)
				max = sum;
		}
		for (int j = 0; j < MAX; j++) {
			sum = 0;
			for (int k = 0; k < MAX; k++) {
				sum += map[k][j];
			}
			if (max < sum)
				max = sum;
		}
		sum = 0;
		for (int j = 0; j < MAX; j++) {
			sum += map[j][j];
		}
		if (max < sum)
			max = sum;

		sum = 0;
		for (int j = 0; j < MAX; j++) {
			sum += map[j][MAX - 1 - j];
		}
		if (max < sum)
			max = sum;
		
		cout << "#" << n << " " << max << endl;
	}

	return 0;
}