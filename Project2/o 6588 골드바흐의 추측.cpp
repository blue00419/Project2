#include<iostream>
#include<cmath>

using namespace std;

int n;
int map[1000001];
int prime[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int rmax = sqrt((double)1000000) + 1;
	map[0] = 1;
	map[1] = 1;
	for (int i = 2; i <= rmax; i++) {
		if (map[i] == 0) {
			for (int j = i + i; j <= 1000000; j = j + i) {
				map[j] = 1;
			}
		}
	}
	int count = 0;
	for (int i = 3; i <= 1000000; i++) {
		if (map[i] == 0) {
			prime[count] = i;
			count++;
			map[i] = i;
		}
	}

	bool end;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		end = false;
		for (int i = 0; i < n/2; i++) {
			if (prime[i] + map[n - prime[i]] == n) {
				cout << n << " = " << prime[i] << " + " << map[n - prime[i]] << '\n';
				end = true;
				break;
			}
		}
		if (!end) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}

	return 0;
}