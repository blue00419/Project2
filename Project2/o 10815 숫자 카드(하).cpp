#include<iostream>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<int, int> a;
	int n, m;

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a[temp] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (a.count(temp)) {
			printf("1");
		}
		else {
			printf("0");
		}
		if (i != m - 1) {
			printf(" ");
		}
	}
	return 0;
}