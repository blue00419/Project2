#include<iostream>
#include<cstring>

using namespace std;

#define MAX 100000+1

int map[MAX];
int counter = 0;
bool ok = true;

int f(int a) {
	if (a == map[a]) return a;

	int b = f(map[a]);
	map[a] = b;
	return b;
}

void u(int a) {
	a = f(a);

	if (a == 0) {
		ok = false;
		return;
	}
	map[a] = a - 1;
	counter++;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		map[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (ok) {
			u(a);
		}
	}
	cout << counter << endl;
	return 0;
}