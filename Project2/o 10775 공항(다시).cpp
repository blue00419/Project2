#include<iostream>

using namespace std;

#define MAX 100000+1

int map[MAX];
int counter = 0;
bool ok = true;

int find(int a) {
	if (a == map[a]) return a;

	int b = find(map[a]);
	map[a] = b;
	return b;
}

void Union(int a) {

	a = find(a);

	if (a == 0) {
		ok = false;
		return;
	}
	map[a] = a - 1;
	counter++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int g, p, a;
	cin >> g >> p;

	for (int i = 0; i <= g; i++) {
		map[i] = i;
	}

	for (int i = 0; i < p; i++) {
		cin >> a;

		if (ok) {
			Union(a);
		}
	}

	cout << counter << endl;

	return 0;
}