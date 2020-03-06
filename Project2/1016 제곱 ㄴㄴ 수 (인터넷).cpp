#include<iostream>

using namespace std;

#define MAX 1000000

long long a, b;
long long map[MAX + 1] = { 0, };

int main() {
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	for (long long i = 2; i * i <= b; i++) {

		long long x = a / (i * i);
		if (a % (i * i) != 0)
			x++;

		while (x * (i * i) <= b) {
			map[x * (i * i) - a] = 1;
			x++;
		}
	}

	int count = 0;
	for (int i = 0; i <= b - a; i++) {
		if (map[i] == 0) {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}