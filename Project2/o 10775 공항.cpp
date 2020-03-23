#include<iostream>

using namespace std;

int map[100001];

int find(int x) {
	if (x == map[x]) return x;
	int y = find(map[x]);
	map[x] = y;
	return y;
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	map[x] = y;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int g, p;

	cin >> g >> p;

	for (int i = 1; i <= g; i++) {
		map[i] = i;
	}

	int temp, count=0;
	bool ok = true;
	for (int i = 0; i < p; i++) {
		cin >> temp;

		int docking = find(temp);
		if (docking != 0 && ok) {
			Union(docking, docking - 1);
			count++;
		}
		else
			ok = false;
	}
	cout << count << endl;


	return 0;
}