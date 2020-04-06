#include<iostream>

using namespace std;

#define MAX 400+1

int map[MAX];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int n;
	int a, b;
	int temp;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		memset(map, 0, sizeof(map));
		cout << endl;
		int max = 0;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			if (a > b) {
				temp = a;
				a = b;
				b = temp;
			}
			if (a % 2 == 0) {
				a--;
			}
			if (b % 2 != 0) {
				b++;
			}
			cout << a << " " << b << endl;
			for (int k = a; k <= b; k++) {
				map[k]++;
				if (map[k] > max)
					max = map[k];
			}
		}

		cout << "#" << i << " " << max << endl;
	}


	return 0;
}