#include<iostream>

using namespace std;


int main() {

	int n;
	cin >> n;

	int* map = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int s, e;
	cin >> s >> e;

	int sum = 0;
	for (int i = s - 1; i < e; i++) {
		sum += map[i];
	}
	cout << sum << endl;


	return 0;
}