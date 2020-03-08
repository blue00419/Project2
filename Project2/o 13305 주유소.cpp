#include<iostream>

using namespace std;

int n;
long long road[100000] = { 0, };
long long coast[100001] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> road[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> coast[i];
	}

	long long c = coast[1], l = road[1], sum = 0;
	for (int i = 2; i <= n; i++) {
		if (coast[i] <= c || i==n) {
			sum += c * l;
			c = coast[i];
			l = 0;
		}
		if (i != n) {
			l += road[i];
		}
	}

	cout << sum << '\n';
	return 0;
}